#include <cstdio>
#include <cstdlib>

struct Process {
    int time;
    Process* next;
};

class RoundRobinScheduler {
private:
    Process* head;
    int time_slot;

public:
    RoundRobinScheduler(int slot) {
        head = NULL;
        time_slot = slot;
    }
    void insertProcess(int);
    void execute();
};
 
int main() {
    int choice, time, time_slot;
    
    printf("Enter the fixed time slot for processes: ");
    scanf("%d", &time_slot);
    
    RoundRobinScheduler scheduler(time_slot);
    
    while (1) {
        printf("\n1. Insert Process\n2. Execute\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter process time: ");
                scanf("%d", &time);
                scheduler.insertProcess(time);
                break;
            case 2:
                scheduler.execute();
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
void RoundRobinScheduler::insertProcess(int time) {
    Process* newProcess = (Process*)malloc(sizeof(Process));
    newProcess->time = time;
    newProcess->next = NULL;
    
    if (head == NULL) {
        head = newProcess;
        newProcess->next = head;
    } else {
        Process* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newProcess;
        newProcess->next = head;
    }
    printf("Process with time %d inserted.\n", time);
}
void RoundRobinScheduler::execute() {
    if (head == NULL) {
        printf("No processes to execute.\n");
        return;
    }
    Process* temp = head;
    Process* prev = NULL;
    
    do {
        printf("Executing process with time %d.\n", temp->time);
        temp->time -= time_slot;
        
        if (temp->time <= 0) {
            printf("Process completed.\n");
            
            if (temp == head && temp->next == head) { // Only one process left
                free(temp);
                head = NULL;
                return;
            }
            if (temp == head) {
                prev = head;
                while (prev->next != head) {
                    prev = prev->next;
                }
                head = head->next;
                prev->next = head;
                free(temp);
                temp = head;
            } else {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            }
        } else {
            printf("Remaining time: %d\n", temp->time);
            prev = temp;
            temp = temp->next;
        }
    } while (head != NULL && temp != head);
}