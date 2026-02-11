def garden_operations(Error_Types):
    if Error_Types == "Value_E":
        num = int("abc")
        print(num)
    if Error_Types == "0_Div_E":
        num = 0/0
        print(num)
    if Error_Types == "No_File_E":
        file = open("")
        file.close()
    if Error_Types == "Key_E":
        dict = {'1': '1', '2': '2', '3': '3'}
        num = dict['4']
        print(num)


def test_error_types():
    print("=== Garden Error Types Demo ===\n")
    try:
        print("Testing ValueError...")
        garden_operations('Value_E')
    except ValueError as e:
        print(f"Caught ValueError: {e}\n")
    try:
        print("Testing ZeroDivisionError...")
        garden_operations('0_Div_E')
    except ZeroDivisionError as e:
        print(f"Caught ZeroDivisionError: {e}\n")
    try:
        print('Testing FileNotFoundError...')
        garden_operations('No_File_E')
    except FileNotFoundError as e:
        print(f"Caught FileNotFoundError: {e}\n")
    try:
        print('Testing KeyError...')
        garden_operations('Key_E')
    except KeyError as e:
        print(f"Caught KeyError: {e}\n")
    try:
        print('Testing multiple errors together......')
        garden_operations('No_File_E')
        garden_operations('Key_E')
    except Exception:
        print("Caught an error, but program continues: \n")
    print('All error types tested successfully')


test_error_types()
