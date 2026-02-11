class GardenError(Exception):
    def init(self, message):
        self.message = message


class PlantError(GardenError):
    def init(self):
        message = 'The tomato plant is wilting!'
        super().init(message)


class WaterError(GardenError):
    def init(self):
        message = 'Not enough water in the tank!'
        super().init(message)


def test_plant(plant_water):
    if plant_water not in range(5, 15):
        raise PlantError()


def test_water(water_level):
    if water_level < 0:
        raise WaterError()


def Error_type(Error, input):
    try:
        Error(input)
    except GardenError as e:
        return e


def test_errors():
    print("=== Custom Garden Errors Demo ===\n")
    try:
        print('Testing PlantError...')
        test_plant(2)
    except PlantError as e:
        print(f"Caught PlantError:: {e.message}\n")
    try:
        print('Testing WaterError...')
        test_water(-1)
    except WaterError as e:
        print(f"Caught PlantError:: {e.message}\n")
    message = []
    print('Testing catching all garden errors...')
    error1 = Error_type(test_water, -1)
    if error1:
        message.append(error1.message)
    error2 = Error_type(test_plant, 1)
    if error2:
        message.append(error2.message)
    for i in message:
        print(f'Caught a garden error: {i}')


if __name__ == "__main__":
    test_errors()
