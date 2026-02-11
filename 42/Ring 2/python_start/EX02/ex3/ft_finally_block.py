class customError(Exception):
    def __init__(self, message):
        self.message = message


class is_plant_error(customError):
    def __init__(self):
        message = 'invalid plant!'
        super().__init__(message)


def test_plant(plant):
    if plant is None:
        raise is_plant_error()


def water_plants(plant_list):
    print('Opening watering system')
    try:
        for plant in plant_list:
            test_plant(plant)
            print('Watering', plant)
    except is_plant_error as e:
        print(f'Error: Cannot water {plant} - {e.message}')
    finally:
        print('Closing watering system (cleanup)')
        if plant is not None:
            print('Watering completed successfully!\n')


def test_watering_system():
    print('Testing normal watering...')
    plant_list = []
    plant_list.append("tomato")
    plant_list.append("tree")
    plant_list.append("lettuce")
    plant_list.append("plant")
    water_plants(plant_list)
    print('Testing with error...')
    plant_list[1] = None
    water_plants(plant_list)


if __name__ == "__main__":
    print('== Garden Watering System ===\n')
    test_watering_system()
    print('\nCleanup always happens, even with errors!')
