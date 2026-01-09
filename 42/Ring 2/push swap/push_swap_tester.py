#!/usr/bin/env python3

import subprocess
import random
import sys
import os
from typing import List, Tuple

# ANSI color codes
GREEN = '\033[92m'
RED = '\033[91m'
YELLOW = '\033[93m'
BLUE = '\033[94m'
CYAN = '\033[96m'
RESET = '\033[0m'
BOLD = '\033[1m'

class PushSwapTester:
    def __init__(self, push_swap_path: str = "./push_swap", checker_path: str = "./checker"):
        self.push_swap_path = push_swap_path
        self.checker_path = checker_path
        
    def generate_random_numbers(self, count: int) -> List[int]:
        """Generate random unique numbers"""
        numbers = list(range(1, count + 1))
        random.shuffle(numbers)
        return numbers
    
    def execute_push_swap(self, numbers: List[int]) -> Tuple[str, int]:
        """Execute push_swap and return operations and count"""
        try:
            args = [str(n) for n in numbers]
            result = subprocess.run(
                [self.push_swap_path] + args,
                capture_output=True,
                text=True,
                timeout=5
            )
            operations = result.stdout.strip()
            op_count = len(operations.split('\n')) if operations else 0
            return operations, op_count
        except subprocess.TimeoutExpired:
            return None, -1
        except FileNotFoundError:
            print(f"{RED}Error: push_swap not found at {self.push_swap_path}{RESET}")
            return None, -1
    
    def check_with_checker(self, numbers: List[int], operations: str) -> Tuple[bool, List[int], List[int]]:
        """Verify operations with checker if available"""
        if not os.path.exists(self.checker_path):
            return self.manual_check(numbers, operations)
        
        try:
            args = [str(n) for n in numbers]
            result = subprocess.run(
                [self.checker_path] + args,
                input=operations,
                capture_output=True,
                text=True,
                timeout=5
            )
            is_ok = result.stdout.strip() == "OK"
            if not is_ok:
                # Run manual check to get stack states
                return self.manual_check(numbers, operations)
            return is_ok, [], []
        except (subprocess.TimeoutExpired, FileNotFoundError):
            return self.manual_check(numbers, operations)
    
    def manual_check(self, numbers: List[int], operations: str) -> Tuple[bool, List[int], List[int]]:
        """Manually verify operations without checker"""
        if not operations:
            is_sorted = sorted(numbers) == numbers
            return is_sorted, numbers, []
            
        stack_a = numbers.copy()
        stack_b = []
        
        for op in operations.split('\n'):
            op = op.strip().lower()  # Convert to lowercase
            if not op:
                continue
                
            if op == 'sa' and len(stack_a) >= 2:
                stack_a[0], stack_a[1] = stack_a[1], stack_a[0]
            elif op == 'sb' and len(stack_b) >= 2:
                stack_b[0], stack_b[1] = stack_b[1], stack_b[0]
            elif op == 'ss':
                if len(stack_a) >= 2:
                    stack_a[0], stack_a[1] = stack_a[1], stack_a[0]
                if len(stack_b) >= 2:
                    stack_b[0], stack_b[1] = stack_b[1], stack_b[0]
            elif op == 'pa' and stack_b:
                stack_a.insert(0, stack_b.pop(0))
            elif op == 'pb' and stack_a:
                stack_b.insert(0, stack_a.pop(0))
            elif op == 'ra' and stack_a:
                stack_a.append(stack_a.pop(0))
            elif op == 'rb' and stack_b:
                stack_b.append(stack_b.pop(0))
            elif op == 'rr':
                if stack_a:
                    stack_a.append(stack_a.pop(0))
                if stack_b:
                    stack_b.append(stack_b.pop(0))
            elif op == 'rra' and stack_a:
                stack_a.insert(0, stack_a.pop())
            elif op == 'rrb' and stack_b:
                stack_b.insert(0, stack_b.pop())
            elif op == 'rrr':
                if stack_a:
                    stack_a.insert(0, stack_a.pop())
                if stack_b:
                    stack_b.insert(0, stack_b.pop())
        
        is_sorted = stack_a == sorted(numbers) and len(stack_b) == 0
        return is_sorted, stack_a, stack_b
    
    def get_grade(self, count: int, operations: int) -> str:
        """Calculate grade based on operation count"""
        if count == 3:
            if operations <= 3:
                return f"{GREEN}Perfect!{RESET}"
            else:
                return f"{RED}Too many operations{RESET}"
        elif count == 5:
            if operations <= 12:
                return f"{GREEN}Excellent!{RESET}"
            else:
                return f"{YELLOW}Could be better{RESET}"
        elif count == 100:
            if operations < 700:
                return f"{GREEN}Grade: 5{RESET}"
            elif operations < 900:
                return f"{GREEN}Grade: 4{RESET}"
            elif operations < 1100:
                return f"{GREEN}Grade: 3{RESET}"
            elif operations < 1300:
                return f"{YELLOW}Grade: 2{RESET}"
            elif operations < 1500:
                return f"{YELLOW}Grade: 1{RESET}"
            else:
                return f"{RED}Grade: 0{RESET}"
        elif count == 500:
            if operations < 5500:
                return f"{GREEN}Grade: 5{RESET}"
            elif operations < 7000:
                return f"{GREEN}Grade: 4{RESET}"
            elif operations < 8500:
                return f"{GREEN}Grade: 3{RESET}"
            elif operations < 10000:
                return f"{YELLOW}Grade: 2{RESET}"
            elif operations < 11500:
                return f"{YELLOW}Grade: 1{RESET}"
            else:
                return f"{RED}Grade: 0{RESET}"
        return ""
    
    def test_case(self, numbers: List[int], name: str) -> Tuple[bool, int]:
        """Test a single case"""
        print(f"\n{CYAN}Testing: {name}{RESET}")
        print(f"Input: {' '.join(map(str, numbers[:10]))}{'...' if len(numbers) > 10 else ''}")
        
        operations, op_count = self.execute_push_swap(numbers)
        
        if operations is None:
            print(f"{RED}✗ Failed to execute push_swap{RESET}")
            return False, 0
        
        is_sorted, stack_a, stack_b = self.check_with_checker(numbers, operations)
        
        if is_sorted:
            grade = self.get_grade(len(numbers), op_count)
            print(f"{GREEN}✓ Sorted correctly{RESET}")
            print(f"Operations: {BOLD}{op_count}{RESET} {grade}")
            return True, op_count
        else:
            print(f"{RED}✗ Not sorted correctly{RESET}")
            print(f"Operations used: {op_count}")
            
            # Show what went wrong
            if stack_a or stack_b:
                print(f"\n{YELLOW}Original input:{RESET}")
                print(f"{' '.join(map(str, numbers))}")
                
                print(f"\n{YELLOW}To reproduce this test, run:{RESET}")
                print(f"./push_swap {' '.join(map(str, numbers))}")
                
                print(f"\n{YELLOW}Final state:{RESET}")
                print(f"Stack A: {' '.join(map(str, stack_a)) if stack_a else '(empty)'}")
                print(f"Stack B: {' '.join(map(str, stack_b)) if stack_b else '(empty)'}")
                
                expected = sorted(numbers)
                print(f"\n{YELLOW}Expected (sorted): {' '.join(map(str, expected))}{RESET}")
                
                if stack_b:
                    print(f"{RED}Error: Stack B is not empty!{RESET}")
                if stack_a != expected:
                    print(f"{RED}Error: Stack A is not sorted!{RESET}")
            
            return False, op_count
    
    def run_tests(self):
        """Run all tests"""
        print(f"\n{BOLD}{BLUE}{'='*60}{RESET}")
        print(f"{BOLD}{BLUE}PUSH_SWAP TESTER{RESET}")
        print(f"{BOLD}{BLUE}{'='*60}{RESET}\n")
        
        if not os.path.exists(self.push_swap_path):
            print(f"{RED}Error: push_swap executable not found!{RESET}")
            print(f"Expected path: {self.push_swap_path}")
            print(f"Please compile your push_swap first or specify correct path.")
            return
        
        results = []
        
        # Test with 3 numbers
        print(f"\n{BOLD}--- Testing with 3 numbers ---{RESET}")
        for i in range(3):
            numbers = self.generate_random_numbers(3)
            passed, ops = self.test_case(numbers, f"Random test {i+1}/3")
            results.append(('3 numbers', passed, ops))
        
        # Test with 5 numbers
        print(f"\n{BOLD}--- Testing with 5 numbers ---{RESET}")
        for i in range(3):
            numbers = self.generate_random_numbers(5)
            passed, ops = self.test_case(numbers, f"Random test {i+1}/3")
            results.append(('5 numbers', passed, ops))
        
        # Test with 100 numbers
        print(f"\n{BOLD}--- Testing with 100 numbers ---{RESET}")
        for i in range(3):
            numbers = self.generate_random_numbers(100)
            passed, ops = self.test_case(numbers, f"Random test {i+1}/3")
            results.append(('100 numbers', passed, ops))
        
        # Test with 500 numbers
        print(f"\n{BOLD}--- Testing with 500 numbers ---{RESET}")
        for i in range(2):
            numbers = self.generate_random_numbers(500)
            passed, ops = self.test_case(numbers, f"Random test {i+1}/2")
            results.append(('500 numbers', passed, ops))
        
        # Edge cases
        print(f"\n{BOLD}--- Edge Cases ---{RESET}")
        
        # Already sorted
        numbers = list(range(1, 6))
        passed, ops = self.test_case(numbers, "Already sorted (5 numbers)")
        results.append(('Edge case', passed, ops))
        
        # Reverse sorted
        numbers = list(range(5, 0, -1))
        passed, ops = self.test_case(numbers, "Reverse sorted (5 numbers)")
        results.append(('Edge case', passed, ops))
        
        # Summary
        print(f"\n{BOLD}{BLUE}{'='*60}{RESET}")
        print(f"{BOLD}{BLUE}SUMMARY{RESET}")
        print(f"{BOLD}{BLUE}{'='*60}{RESET}\n")
        
        passed_count = sum(1 for _, passed, _ in results if passed)
        total_count = len(results)
        
        print(f"Tests passed: {GREEN if passed_count == total_count else RED}{passed_count}/{total_count}{RESET}")
        
        if passed_count == total_count:
            print(f"\n{GREEN}{BOLD}🎉 All tests passed!{RESET}")
        else:
            print(f"\n{RED}{BOLD}Some tests failed. Keep improving!{RESET}")

def main():
    # Check if testing single case
    if len(sys.argv) > 1 and sys.argv[1] == "test":
        # python3 push_swap_tester.py test 2 1 3
        push_swap_path = "./push_swap"
        tester = PushSwapTester(push_swap_path)
        
        numbers = [int(x) for x in sys.argv[2:]]
        print(f"\n{CYAN}Testing single case:{RESET}")
        print(f"Input: {' '.join(map(str, numbers))}")
        
        operations, op_count = tester.execute_push_swap(numbers)
        
        if operations is None:
            print(f"{RED}✗ Failed to execute push_swap{RESET}")
            return
        
        print(f"\n{BOLD}Operations:{RESET}")
        print(operations)
        print(f"\n{BOLD}Operation count:{RESET} {op_count}")
        
        is_sorted, stack_a, stack_b = tester.manual_check(numbers, operations)
        
        if is_sorted:
            grade = tester.get_grade(len(numbers), op_count)
            print(f"\n{GREEN}✓ Result: Sorted correctly!{RESET} {grade}")
        else:
            print(f"\n{RED}✗ Result: NOT sorted correctly{RESET}")
            
            # Show what went wrong
            print(f"\n{YELLOW}Original input:{RESET}")
            print(f"{' '.join(map(str, numbers))}")
            
            print(f"\n{YELLOW}To reproduce this test, run:{RESET}")
            print(f"./push_swap {' '.join(map(str, numbers))}")
            
            print(f"\n{YELLOW}Final state:{RESET}")
            print(f"Stack A: {' '.join(map(str, stack_a)) if stack_a else '(empty)'}")
            print(f"Stack B: {' '.join(map(str, stack_b)) if stack_b else '(empty)'}")
            
            expected = sorted(numbers)
            print(f"\n{YELLOW}Expected (sorted): {' '.join(map(str, expected))}{RESET}")
            
            if stack_b:
                print(f"{RED}Error: Stack B is not empty!{RESET}")
            if stack_a != expected:
                print(f"{RED}Error: Stack A is not sorted!{RESET}")
        
        return
    
    # Run full test suite
    if len(sys.argv) > 1:
        push_swap_path = sys.argv[1]
    else:
        push_swap_path = "./push_swap"
    
    checker_path = "./checker" if len(sys.argv) <= 2 else sys.argv[2]
    
    tester = PushSwapTester(push_swap_path, checker_path)
    tester.run_tests()

if __name__ == "__main__":
    main()