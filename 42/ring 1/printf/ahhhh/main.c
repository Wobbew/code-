#include <stdio.h>
#include <limits.h>
#include <string.h>

// Include your ft_printf header
int ft_printf(const char *format, ...);

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define RESET "\033[0m"

int g_test_num = 1;
int g_passed = 0;
int g_failed = 0;

void print_test_header(const char *category) {
    printf("\n%s=== %s ===%s\n", YELLOW, category, RESET);
}

void compare_outputs(const char *test_name, const char *format, int ft_ret, int std_ret) {
    printf("Test %d: %s\n", g_test_num++, test_name);
    printf("  Format: \"%s\"\n", format);
    printf("  ft_printf return: %d | printf return: %d\n", ft_ret, std_ret);
    
    if (ft_ret == std_ret) {
        printf("  %s✓ PASS%s\n", GREEN, RESET);
        g_passed++;
    } else {
        printf("  %s✗ FAIL%s (return values don't match)\n", RED, RESET);
        g_failed++;
    }
    printf("\n");
}

void test_char() {
    print_test_header("CHARACTER TESTS (%c)");
    
    int ft, std;
    
    printf("ft_printf: "); ft = ft_printf("Char: %c\n", 'A');
    printf("printf:    "); std = printf("Char: %c\n", 'A');
    compare_outputs("Basic char", "%c", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("Multiple: %c %c %c\n", 'X', 'Y', 'Z');
    printf("printf:    "); std = printf("Multiple: %c %c %c\n", 'X', 'Y', 'Z');
    compare_outputs("Multiple chars", "%c %c %c", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("%c\n", 0);
    printf("printf:    "); std = printf("%c\n", 0);
    compare_outputs("Null char", "%c", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("%c%c%c\n", 'a', 'b', 'c');
    printf("printf:    "); std = printf("%c%c%c\n", 'a', 'b', 'c');
    compare_outputs("No space between chars", "%c%c%c", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("%c\n", 127);
    printf("printf:    "); std = printf("%c\n", 127);
    compare_outputs("DEL character", "%c (127)", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("%c\n", -128);
    printf("printf:    "); std = printf("%c\n", -128);
    compare_outputs("Negative char value", "%c (-128)", ft, std);
}

void test_string() {
    print_test_header("STRING TESTS (%s)");
    
    int ft, std;
    
    printf("ft_printf: "); ft = ft_printf("String: %s\n", "Hello");
    printf("printf:    "); std = printf("String: %s\n", "Hello");
    compare_outputs("Basic string", "%s", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("Empty: %s\n", "");
    printf("printf:    "); std = printf("Empty: %s\n", "");
    compare_outputs("Empty string", "%s", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("NULL: %s\n", (char *)NULL);
    printf("printf:    "); std = printf("NULL: %s\n", (char *)NULL);
    compare_outputs("NULL string", "%s", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("%s %s %s\n", "One", "Two", "Three");
    printf("printf:    "); std = printf("%s %s %s\n", "One", "Two", "Three");
    compare_outputs("Multiple strings", "%s %s %s", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("%s%s%s\n", "No", "Space", "Here");
    printf("printf:    "); std = printf("%s%s%s\n", "No", "Space", "Here");
    compare_outputs("Concatenated strings", "%s%s%s", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("%s\n", "String with special chars: !@#$%^&*()");
    printf("printf:    "); std = printf("%s\n", "String with special chars: !@#$%^&*()");
    compare_outputs("Special characters", "%s (special)", ft, std);
}

void test_pointer() {
    print_test_header("POINTER TESTS (%p)");
    
    int ft, std;
    int x = 42;
    
    printf("ft_printf: "); ft = ft_printf("Pointer: %p\n", &x);
    printf("printf:    "); std = printf("Pointer: %p\n", &x);
    compare_outputs("Valid pointer", "%p", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("NULL: %p\n", NULL);
    printf("printf:    "); std = printf("NULL: %p\n", NULL);
    compare_outputs("NULL pointer", "%p", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("%p %p\n", &x, &ft);
    printf("printf:    "); std = printf("%p %p\n", &x, &ft);
    compare_outputs("Multiple pointers", "%p %p", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("%p\n", (void *)1);
    printf("printf:    "); std = printf("%p\n", (void *)1);
    compare_outputs("Pointer value 1", "%p (1)", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("%p\n", (void *)-1);
    printf("printf:    "); std = printf("%p\n", (void *)-1);
    compare_outputs("Pointer value -1", "%p (-1)", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("%p\n", (void *)LONG_MAX);
    printf("printf:    "); std = printf("%p\n", (void *)LONG_MAX);
    compare_outputs("LONG_MAX as pointer", "%p (LONG_MAX)", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("%p\n", (void *)LONG_MIN);
    printf("printf:    "); std = printf("%p\n", (void *)LONG_MIN);
    compare_outputs("LONG_MIN as pointer", "%p (LONG_MIN)", ft, std);
}

void test_decimal() {
    print_test_header("DECIMAL TESTS (%d, %i)");
    
    int ft, std;
    
    printf("ft_printf: "); ft = ft_printf("Decimal: %d\n", 42);
    printf("printf:    "); std = printf("Decimal: %d\n", 42);
    compare_outputs("Positive number", "%d", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("Negative: %d\n", -42);
    printf("printf:    "); std = printf("Negative: %d\n", -42);
    compare_outputs("Negative number", "%d", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("Zero: %d\n", 0);
    printf("printf:    "); std = printf("Zero: %d\n", 0);
    compare_outputs("Zero", "%d", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("INT_MAX: %d\n", INT_MAX);
    printf("printf:    "); std = printf("INT_MAX: %d\n", INT_MAX);
    compare_outputs("INT_MAX", "%d", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("INT_MIN: %d\n", INT_MIN);
    printf("printf:    "); std = printf("INT_MIN: %d\n", INT_MIN);
    compare_outputs("INT_MIN", "%d", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("Integer %%i: %i\n", 123);
    printf("printf:    "); std = printf("Integer %%i: %i\n", 123);
    compare_outputs("%%i format", "%i", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("%d %d %d\n", -2147483648, 0, 2147483647);
    printf("printf:    "); std = printf("%d %d %d\n", -2147483648, 0, 2147483647);
    compare_outputs("Min, Zero, Max", "%d %d %d", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("%i\n", -0);
    printf("printf:    "); std = printf("%i\n", -0);
    compare_outputs("Negative zero", "%i (-0)", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("%d%d%d%d%d\n", 1, 2, 3, 4, 5);
    printf("printf:    "); std = printf("%d%d%d%d%d\n", 1, 2, 3, 4, 5);
    compare_outputs("Consecutive numbers", "%d%d%d%d%d", ft, std);
}

void test_unsigned() {
    print_test_header("UNSIGNED TESTS (%u)");
    
    int ft, std;
    
    printf("ft_printf: "); ft = ft_printf("Unsigned: %u\n", 42);
    printf("printf:    "); std = printf("Unsigned: %u\n", 42);
    compare_outputs("Positive unsigned", "%u", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("Zero: %u\n", 0);
    printf("printf:    "); std = printf("Zero: %u\n", 0);
    compare_outputs("Zero unsigned", "%u", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("UINT_MAX: %u\n", UINT_MAX);
    printf("printf:    "); std = printf("UINT_MAX: %u\n", UINT_MAX);
    compare_outputs("UINT_MAX", "%u", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("Negative as unsigned: %u\n", -1);
    printf("printf:    "); std = printf("Negative as unsigned: %u\n", -1);
    compare_outputs("Negative as unsigned (-1)", "%u", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("%u\n", -42);
    printf("printf:    "); std = printf("%u\n", -42);
    compare_outputs("Negative as unsigned (-42)", "%u (-42)", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("%u\n", INT_MIN);
    printf("printf:    "); std = printf("%u\n", INT_MIN);
    compare_outputs("INT_MIN as unsigned", "%u (INT_MIN)", ft, std);
}

void test_hex() {
    print_test_header("HEXADECIMAL TESTS (%x, %X)");
    
    int ft, std;
    
    printf("ft_printf: "); ft = ft_printf("Hex lowercase: %x\n", 255);
    printf("printf:    "); std = printf("Hex lowercase: %x\n", 255);
    compare_outputs("Lowercase hex (255)", "%x", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("Hex uppercase: %X\n", 255);
    printf("printf:    "); std = printf("Hex uppercase: %X\n", 255);
    compare_outputs("Uppercase hex (255)", "%X", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("Zero: %x\n", 0);
    printf("printf:    "); std = printf("Zero: %x\n", 0);
    compare_outputs("Zero hex", "%x", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("UINT_MAX: %x\n", UINT_MAX);
    printf("printf:    "); std = printf("UINT_MAX: %x\n", UINT_MAX);
    compare_outputs("UINT_MAX hex", "%x", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("Mix: %x %X\n", 42, 42);
    printf("printf:    "); std = printf("Mix: %x %X\n", 42, 42);
    compare_outputs("Mixed case hex", "%x %X", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("%x\n", -1);
    printf("printf:    "); std = printf("%x\n", -1);
    compare_outputs("Negative as hex (-1)", "%x (-1)", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("%x\n", -42);
    printf("printf:    "); std = printf("%x\n", -42);
    compare_outputs("Negative as hex (-42)", "%x (-42)", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("%X\n", INT_MIN);
    printf("printf:    "); std = printf("%X\n", INT_MIN);
    compare_outputs("INT_MIN as hex", "%X (INT_MIN)", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("%x%X%x\n", 10, 11, 12);
    printf("printf:    "); std = printf("%x%X%x\n", 10, 11, 12);
    compare_outputs("Consecutive hex", "%x%X%x", ft, std);
}

void test_percent() {
    print_test_header("PERCENT TESTS (%%)");
    
    int ft, std;
    
    printf("ft_printf: "); ft = ft_printf("Percent: %%\n");
    printf("printf:    "); std = printf("Percent: %%\n");
    compare_outputs("Single percent", "%%", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("Multiple: %%%% %%\n");
    printf("printf:    "); std = printf("Multiple: %%%% %%\n");
    compare_outputs("Multiple percents", "%%%% %%", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("100%% complete\n");
    printf("printf:    "); std = printf("100%% complete\n");
    compare_outputs("Percent in text", "100%%", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("%%%%%%%%\n");
    printf("printf:    "); std = printf("%%%%%%%%\n");
    compare_outputs("Many percents", "%%%%%%%%", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("%%");
    printf("printf:    "); std = printf("%%");
    compare_outputs("Percent no newline", "%% (no newline)", ft, std);
    printf("\n");
}

void test_mixed() {
    print_test_header("MIXED FORMAT TESTS");
    
    int ft, std;
    
    printf("ft_printf: "); ft = ft_printf("Mix: %c %s %d %x\n", 'A', "test", 42, 255);
    printf("printf:    "); std = printf("Mix: %c %s %d %x\n", 'A', "test", 42, 255);
    compare_outputs("Multiple formats", "%c %s %d %x", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("Complex: %d + %d = %d, %s!\n", 2, 2, 4, "Easy");
    printf("printf:    "); std = printf("Complex: %d + %d = %d, %s!\n", 2, 2, 4, "Easy");
    compare_outputs("Complex sentence", "Complex format", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("%p %p %p\n", (void *)0, (void *)1, (void *)-1);
    printf("printf:    "); std = printf("%p %p %p\n", (void *)0, (void *)1, (void *)-1);
    compare_outputs("Edge pointers", "%p %p %p", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("%s%c%d%u%x%X%p%%\n", "Hi", '!', -1, 42, 255, 255, &ft);
    printf("printf:    "); std = printf("%s%c%d%u%x%X%p%%\n", "Hi", '!', -1, 42, 255, 255, &ft);
    compare_outputs("All formats no space", "All formats", ft, std);
}

void test_weird_edge_cases() {
    print_test_header("WEIRD EDGE CASES");
    
    int ft, std;
    
    printf("ft_printf: "); ft = ft_printf("");
    printf("printf:    "); std = printf("");
    compare_outputs("Empty string", "", ft, std);
    printf("\n");
    
    printf("ft_printf: "); ft = ft_printf("No format specifiers here!\n");
    printf("printf:    "); std = printf("No format specifiers here!\n");
    compare_outputs("No specifiers", "plain text", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("%d%d%d%d%d\n", 1, 2, 3, 4, 5);
    printf("printf:    "); std = printf("%d%d%d%d%d\n", 1, 2, 3, 4, 5);
    compare_outputs("No spaces", "%d%d%d%d%d", ft, std);
    
    printf("ft_printf: "); ft = ft_printf(" %c %c %c ", 'a', 'b', 'c');
    printf("printf:    "); std = printf(" %c %c %c ", 'a', 'b', 'c');
    compare_outputs("Leading/trailing spaces", " %c %c %c ", ft, std);
    printf("\n");
    
    printf("ft_printf: "); ft = ft_printf("%c", '\0');
    printf("printf:    "); std = printf("%c", '\0');
    compare_outputs("Null byte only", "%c (null)", ft, std);
    printf("\n");
    
    printf("ft_printf: "); ft = ft_printf("before%cafter", '\0');
    printf("printf:    "); std = printf("before%cafter", '\0');
    compare_outputs("Null in middle", "before%cafter", ft, std);
    printf("\n");
    
    printf("ft_printf: "); ft = ft_printf("%s", "");
    printf("printf:    "); std = printf("%s", "");
    compare_outputs("Empty string no newline", "%s (empty)", ft, std);
    printf("\n");
    
    printf("ft_printf: "); ft = ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%p%%\n", 'c', "s", 1, 2, 3, 4, 5, (void *)6);
    printf("printf:    "); std = printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%p%%\n", 'c', "s", 1, 2, 3, 4, 5, (void *)6);
    compare_outputs("Percent between formats", "%%between%%", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("   \n");
    printf("printf:    "); std = printf("   \n");
    compare_outputs("Just spaces and newline", "spaces+newline", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("\n");
    printf("printf:    "); std = printf("\n");
    compare_outputs("Just newline", "newline only", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("\t%d\t%s\t\n", 42, "tab");
    printf("printf:    "); std = printf("\t%d\t%s\t\n", 42, "tab");
    compare_outputs("With tabs", "\\t%d\\t%s\\t", ft, std);
}

void test_stress() {
    print_test_header("STRESS TESTS");
    
    int ft, std;
    
    printf("ft_printf: "); 
    ft = ft_printf("%d %d %d %d %d %d %d %d %d %d\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    printf("printf:    "); 
    std = printf("%d %d %d %d %d %d %d %d %d %d\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    compare_outputs("10 integers", "10x %d", ft, std);
    
    printf("ft_printf: "); 
    ft = ft_printf("%s %s %s %s %s\n", "One", "Two", "Three", "Four", "Five");
    printf("printf:    "); 
    std = printf("%s %s %s %s %s\n", "One", "Two", "Three", "Four", "Five");
    compare_outputs("5 strings", "5x %s", ft, std);
    
    printf("ft_printf: "); 
    ft = ft_printf("%c%c%c%c%c%c%c%c%c%c\n", 'a','b','c','d','e','f','g','h','i','j');
    printf("printf:    "); 
    std = printf("%c%c%c%c%c%c%c%c%c%c\n", 'a','b','c','d','e','f','g','h','i','j');
    compare_outputs("10 chars", "10x %c", ft, std);
    
    char long_str[100];
    memset(long_str, 'A', 99);
    long_str[99] = '\0';
    printf("ft_printf: "); ft = ft_printf("%s\n", long_str);
    printf("printf:    "); std = printf("%s\n", long_str);
    compare_outputs("Long string (99 A's)", "%s (99 chars)", ft, std);
    
    printf("ft_printf: "); 
    ft = ft_printf("%d%i%u%x%X%d%i%u%x%X\n", 1,2,3,4,5,6,7,8,9,10);
    printf("printf:    "); 
    std = printf("%d%i%u%x%X%d%i%u%x%X\n", 1,2,3,4,5,6,7,8,9,10);
    compare_outputs("Mixed number formats", "mixed nums", ft, std);
}

void test_tricky_numbers() {
    print_test_header("TRICKY NUMBER TESTS");
    
    int ft, std;
    
    printf("ft_printf: "); ft = ft_printf("%d\n", 1);
    printf("printf:    "); std = printf("%d\n", 1);
    compare_outputs("Single digit", "%d (1)", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("%d\n", -1);
    printf("printf:    "); std = printf("%d\n", -1);
    compare_outputs("Negative single digit", "%d (-1)", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("%d\n", 9);
    printf("printf:    "); std = printf("%d\n", 9);
    compare_outputs("Max single digit", "%d (9)", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("%d\n", 10);
    printf("printf:    "); std = printf("%d\n", 10);
    compare_outputs("Two digits start", "%d (10)", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("%d\n", 99);
    printf("printf:    "); std = printf("%d\n", 99);
    compare_outputs("Two digits max", "%d (99)", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("%d\n", 100);
    printf("printf:    "); std = printf("%d\n", 100);
    compare_outputs("Three digits start", "%d (100)", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("%d\n", 999);
    printf("printf:    "); std = printf("%d\n", 999);
    compare_outputs("Three digits max", "%d (999)", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("%d\n", 1000);
    printf("printf:    "); std = printf("%d\n", 1000);
    compare_outputs("Four digits start", "%d (1000)", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("%u\n", 0);
    printf("printf:    "); std = printf("%u\n", 0);
    compare_outputs("Unsigned zero", "%u (0)", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("%x\n", 1);
    printf("printf:    "); std = printf("%x\n", 1);
    compare_outputs("Hex single digit", "%x (1)", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("%x\n", 15);
    printf("printf:    "); std = printf("%x\n", 15);
    compare_outputs("Hex f", "%x (15/f)", ft, std);
    
    printf("ft_printf: "); ft = ft_printf("%x\n", 16);
    printf("printf:    "); std = printf("%x\n", 16);
    compare_outputs("Hex 10", "%x (16/10)", ft, std);
}

int main(void) {
    printf("%s╔══════════════════════════════════════╗%s\n", YELLOW, RESET);
    printf("%s║     FT_PRINTF TESTER v2.0           ║%s\n", YELLOW, RESET);
    printf("%s║        WEIRD EDITION                 ║%s\n", YELLOW, RESET);
    printf("%s╚══════════════════════════════════════╝%s\n", YELLOW, RESET);
    
    test_char();
    test_string();
    test_pointer();
    test_decimal();
    test_unsigned();
    test_hex();
    test_percent();
    test_mixed();
    test_weird_edge_cases();
    test_stress();
    test_tricky_numbers();
    
    printf("\n%s╔══════════════════════════════════════╗%s\n", YELLOW, RESET);
    printf("%s║          TEST SUMMARY                ║%s\n", YELLOW, RESET);
    printf("%s╚══════════════════════════════════════╝%s\n", YELLOW, RESET);
    printf("%sTotal Tests: %d%s\n", YELLOW, g_passed + g_failed, RESET);
    printf("%sPassed: %d%s\n", GREEN, g_passed, RESET);
    printf("%sFailed: %d%s\n", RED, g_failed, RESET);
    
    if (g_failed == 0)
        printf("\n%s🎉 All tests passed! Your ft_printf is solid! 🎉%s\n\n", GREEN, RESET);
    else
        printf("\n%s⚠️  Some tests failed - keep debugging! ⚠️%s\n\n", RED, RESET);
    
    return (g_failed != 0);
}