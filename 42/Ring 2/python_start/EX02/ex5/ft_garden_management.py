class Plant:
    def __init__(self, name, water, sunlight, water_max, water_min,
                 sunlight_max, sunlight_min):
        self.name = name
        self.water = water
        self.sunlight = sunlight
        self.water_max = water_max
        self.water_min = water_min
        self.sunlight_max = sunlight_max
        self.sunlight_min = sunlight_min


class customError(Exception):
    def __init__(self, message):
        self.message = message

    def __str__(self):
        return self.message


def test_plant(plant):
    if plant is None:
        raise customError('Plant name cannot be empty!')


def test_water_plant(water_level, max, min):
    if water_level > max:
        raise customError(f"too wet, the plant likes a max of {max}ml")
    if water_level < min:
        raise customError(f"too dry, the plant likes a minimum of {min}ml")


def test_sunlight_hours(sunlight_hours):
    if sunlight_hours > 12:
        raise customError(
            f"Sunlight hours {sunlight_hours} is too high (max 12)\n")
    if sunlight_hours < 2:
        raise customError(
            f"Sunlight hours {sunlight_hours} is too low (min 2)\n")


class GardenManager():
    def __init__(self, garden_name):
        self.garden_name = garden_name
        self.plants = []

    def add_plant(self, name, water, sun, water_max, water_min, sunlight_max,
                  sunlight_min):
        try:
            test_plant(name)
            plant = Plant(
                name, water, sun, water_max, water_min, sunlight_max,
                sunlight_min)
            self.plants.append(plant)
            print(f'Added {plant.name} - success')
        except customError as e:
            print(f"Error adding plant: {e}")

    def print_plants(self):
        i = 1
        for p in self.plants:
            print(f'plant {i}: {p.name}')
            i = i + 1

    def check_plant_health(self, name):
        try:
            plant = self.find_plant(name)
            test_sunlight_hours(plant.sunlight)
            test_water_plant(plant.water, plant.water_max, plant.water_min)
            print(f"{name} is healthy\nWater level is {plant.water}ml and has"
                  f" {plant.sunlight} hours of sunlight")
        except customError as e:
            print(f"Error checking {name}: {e}")

    def find_plant(self, name):
        for p in self.plants:
            if p.name == name:
                return p
        raise customError("plant does not exist")

    def move_plant(self, name, new_sunlight):
        try:
            plant = self.find_plant(name)
            try:
                test_sunlight_hours(new_sunlight)
            except customError as e:
                print(f"Error: new {e}")
            else:
                print(f"Moving {name} - success\nnew amount of hours"
                      f" in sunlight is {new_sunlight},"
                      f"for {name}")
                plant.sunlight = new_sunlight
        except customError as e:
            print(f"Error: {e}")

    def water_plant(self, name, ml):
        try:
            plant = self.find_plant(name)
            test_water_plant(ml, plant.water_max, plant.water_min)
            plant.water = ml
            print(f'Watering {name} - success\nnew water level is {ml}ml')
        except customError:
            print(f"Error water amount wronue.\nA {name} likes to have a a max\
 of {plant.water_max} and a minimum of {plant.water_min}")


def test_garden_management():
    garden1 = GardenManager("My Garden")
    print('Adding plants to garden...')
    garden1.add_plant('japanese iris', 50, 4, 100, 50, 8, 3)
    garden1.add_plant('Golden barrel cactus', 20, 10, 20, 1, 14, 8)
    garden1.add_plant('tomato', 30, 7, 55, 30, 10, 6)
    garden1.add_plant('Peace lily', 0, 7, 55, 30, 10, 6)
    garden1.add_plant(None, 30, 7, 55, 30, 10, 6)
    print('\nMoving plants...')
    garden1.move_plant('japanese iris', 6)
    garden1.move_plant('Golden barrel cactus', 12)
    print('\nWatering plants...')
    garden1.water_plant('japanese iris', 60)
    print("\nChecking plant health...")
    garden1.check_plant_health('japanese iris')
    garden1.check_plant_health('Peace lily')
    print("\nTesting error recovery..")
    garden1.check_plant_health('Error')
    garden1.move_plant('japanese iris', 1)
    print("System recovered and continuing...")


if __name__ == "__main__":
    print('=== Garden Management System ===')
    test_garden_management()
    print('Garden management system test complete!')
