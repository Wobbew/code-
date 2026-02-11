def test_plant_name(plant):
    if plant is None:
        raise ValueError('plant_name_error\n')


def test_water_level(water_level):
    if water_level > 10:
        raise ValueError(f'Water level {water_level} is too high (max 10)\n')
    if water_level < 1:
        raise ValueError(f'Water level {water_level} is too low (min 1)\n')


def test_sunlight_hours(sunlight_hours):
    if sunlight_hours > 12:
        raise ValueError(f"Sunlight hours {sunlight_hours} is high low (max\
                         12)\n")
    if sunlight_hours < 2:
        raise ValueError(f"Sunlight hours {sunlight_hours} is too low (min 2)\
                         \n")


def check_plant_health(plant_name, water_level, sunlight_hours):
    try:
        test_plant_name(plant_name)
        test_water_level(water_level)
        test_sunlight_hours(sunlight_hours)
        print(f"Plant '{plant_name}' is healthy!\n")
    except ValueError as e:
        print(f'Error: {e}')


def test_plant_checks():
    print("Testing good values...")
    check_plant_health('tomato', 10,  2)
    print('Testing empty plant name...')
    check_plant_health(None, 10,  2)
    print('Testing bad water level...')
    check_plant_health('tomato', 100,  2)
    print("Testing bad sunlight hours...")
    check_plant_health('tomato', 10,  0)


if __name__ == "__main__":
    print('=== Garden Plant Health Checker ===\n')
    test_plant_checks()
    print('All error raising tests completed!')
