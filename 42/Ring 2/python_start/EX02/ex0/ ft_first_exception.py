def check_temperature(temp_str) -> any:
    try:
        num = int(temp_str)
    except ValueError as e:
        print(f"Error: {e}\n")
        return
    if num > 40:
        print(f'Error: {num}°C is too hot for plants (max 40°C)\n')
        return
    if num < 0:
        print(f'Error: {num}°C is too cold for plants (min 0°C)\n')
        return
    print(f'Temperature {num}°C is perfect for plants!\n')
    return (num)


def test_temperature_input():
    print('=== Garden Temperature Checker ===\n')

    print('Testing temperature: 25')
    check_temperature(25)
    print('Testing temperature: abc')
    check_temperature('abc')
    print('Testing temperature: 100')
    check_temperature(100)
    print('Testing temperature: -50')
    check_temperature(-50)
    print("All tests completed - program didn't crash!")


test_temperature_input()