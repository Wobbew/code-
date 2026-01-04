#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

// Colors
#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[0;34m"
#define RESET   "\033[0m"

typedef struct s_result {
    int passed;
    int failed;
    int total_ops;
    int min_ops;
    int max_ops;
} t_result;

// Generate random unique numbers
void generate_numbers(int *arr, int size, int min, int max) {
    int i, j, num, duplicate;
    
    for (i = 0; i < size; i++) {
        do {
            duplicate = 0;
            num = (rand() % (max - min + 1)) + min;
            for (j = 0; j < i; j++) {
                if (arr[j] == num) {
                    duplicate = 1;
                    break;
                }
            }
        } while (duplicate);
        arr[i] = num;
    }
}

// Execute push_swap and count operations
int count_operations(char *args) {
    int pipefd[2];
    pid_t pid;
    int count = 0;
    char buffer[1024];
    ssize_t bytes;
    
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return -1;
    }
    
    pid = fork();
    if (pid == -1) {
        perror("fork");
        return -1;
    }
    
    if (pid == 0) {
        // Child process
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);
        
        // Parse arguments and execute
        char *argv[1024];
        int argc = 0;
        argv[argc++] = "./push_swap";
        
        char *token = strtok(args, " ");
        while (token != NULL && argc < 1023) {
            argv[argc++] = token;
            token = strtok(NULL, " ");
        }
        argv[argc] = NULL;
        
        execv("./push_swap", argv);
        exit(1);
    } else {
        // Parent process
        close(pipefd[1]);
        
        while ((bytes = read(pipefd[0], buffer, sizeof(buffer))) > 0) {
            for (ssize_t i = 0; i < bytes; i++) {
                if (buffer[i] == '\n') count++;
            }
        }
        
        close(pipefd[0]);
        int status;
        waitpid(pid, &status, 0);
        
        if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
            return count;
        }
        return -1;
    }
    return -1;
}

// Test specific case
void test_case(char *numbers, char *description) {
    printf(BLUE "Testing: %s" RESET "\n", description);
    printf("Input: %s\n", numbers);
    
    int ops = count_operations(numbers);
    
    if (ops >= 0) {
        printf("Operations: %d\n", ops);
        printf(GREEN "✓ PASSED" RESET "\n\n");
    } else {
        printf(RED "✗ FAILED - Program crashed" RESET "\n\n");
    }
}

// Run bulk tests
void run_tests(int size, int test_count, int max_ops) {
    printf("\n" YELLOW "========================================" RESET "\n");
    printf(YELLOW "Testing with %d random sets of %d numbers" RESET "\n", test_count, size);
    printf(YELLOW "========================================" RESET "\n\n");
    
    t_result result = {0, 0, 0, 999999, 0};
    int *numbers = malloc(sizeof(int) * size);
    
    for (int i = 0; i < test_count; i++) {
        generate_numbers(numbers, size, -1000, 1000);
        
        // Build argument string
        char args[4096] = "";
        for (int j = 0; j < size; j++) {
            char num[32];
            sprintf(num, "%d ", numbers[j]);
            strcat(args, num);
        }
        
        int ops = count_operations(args);
        
        if (ops >= 0) {
            result.passed++;
            result.total_ops += ops;
            if (ops < result.min_ops) result.min_ops = ops;
            if (ops > result.max_ops) result.max_ops = ops;
            
            if (ops <= max_ops) {
                printf(GREEN "Test %d/%d: ✓ (%d ops)" RESET "\n", i + 1, test_count, ops);
            } else {
                printf(YELLOW "Test %d/%d: ⚠ (%d ops - exceeds %d)" RESET "\n", 
                       i + 1, test_count, ops, max_ops);
            }
        } else {
            result.failed++;
            printf(RED "Test %d/%d: ✗ FAILED" RESET "\n", i + 1, test_count);
        }
    }
    
    printf("\n" YELLOW "Results for %d numbers:" RESET "\n", size);
    printf("Passed: " GREEN "%d" RESET " / %d\n", result.passed, test_count);
    if (result.failed > 0) {
        printf("Failed: " RED "%d" RESET " / %d\n", result.failed, test_count);
    }
    
    if (result.passed > 0) {
        int avg = result.total_ops / result.passed;
        printf("Average operations: %d\n", avg);
        printf("Min operations: %d\n", result.min_ops);
        printf("Max operations: %d\n", result.max_ops);
        
        if (result.max_ops <= max_ops) {
            printf(GREEN "All within limit of %d!" RESET "\n", max_ops);
        } else {
            printf(YELLOW "Some exceeded limit of %d" RESET "\n", max_ops);
        }
    }
    
    free(numbers);
}

int main(void) {
    srand(time(NULL));
    
    // Check if push_swap exists
    if (access("./push_swap", X_OK) != 0) {
        printf(RED "Error: ./push_swap not found or not executable!" RESET "\n");
        printf("Please compile your push_swap first: make\n");
        return 1;
    }
    
    printf(BLUE "╔════════════════════════════════════╗" RESET "\n");
    printf(BLUE "║     PUSH_SWAP TESTER v1.0         ║" RESET "\n");
    printf(BLUE "╚════════════════════════════════════╝" RESET "\n\n");
    
    // Test specific cases
    printf(YELLOW "Testing specific cases..." RESET "\n\n");
    
    test_case("2 1", "2 numbers");
    test_case("3 2 1", "3 numbers (reverse)");
    test_case("2 3 1", "3 numbers (middle wrong)");
    test_case("1 3 2", "3 numbers (last wrong)");
    test_case("5 4 3 2 1", "5 numbers (reverse)");
    test_case("1 2 3 4 5", "5 numbers (already sorted)");
    
    // Test edge cases
    printf("\n" YELLOW "Testing edge cases..." RESET "\n\n");
    test_case("42", "Single number");
    test_case("-5 -10 0 5 10", "Mix of negative and positive");
    test_case("2147483647 -2147483648 0", "INT_MAX and INT_MIN");
    
    // Bulk random tests
    printf("\n" YELLOW "Starting bulk random tests..." RESET "\n");
    
    run_tests(3, 10, 3);      // 3 numbers, max 3 ops
    run_tests(5, 20, 12);     // 5 numbers, max 12 ops
    run_tests(100, 10, 700);  // 100 numbers, max 700 ops
    run_tests(500, 5, 5500);  // 500 numbers, max 5500 ops
    
    printf("\n" BLUE "╔════════════════════════════════════╗" RESET "\n");
    printf(BLUE "║          Testing Complete!         ║" RESET "\n");
    printf(BLUE "╚════════════════════════════════════╝" RESET "\n\n");
    
    return 0;
}