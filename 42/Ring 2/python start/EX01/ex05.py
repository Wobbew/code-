class Plant:
    def __init__(self, name, height, age):
        self.name = name
        self.height = height
        self.age = age

    def print_info(self, type, plus)
         print(f"{self.name}({type}): {self.height}cm, {self.age}" +
              f"{plus}")


class Tree(Plant):
    def __init__(self, name, height, age, trunk_diameter):
        super().__init__(name, height, age)
        self.trunk_diameter = trunk_diameter

    def produce_shade(self):
        shade = self.trunk_diameter * 2.5 + self.height / self.age
        print(f"{self.name} provides {shade} square meters of shade")


class Flower(Plant):
    def __init__(self, name, height, age, color):
        super().__init__(name, height, age)
        self.color = color

    def bloom(self):
        print(f"{self.name} is blooming beautifully!")


class Vegetable(Plant):
    def __init__(self, name, height, age, harvest_season, nutritional_value):
        super().__init__(name, height, age)
        self.harvest_season = harvest_season
        self.nutritional_value = nutritional_value

    def nutritional(self):
        print(f"{self.name} is rich in {self.nutritional_value}")

    def print_info(self):
        super()print_info

if __name__ == "__main__":
    tree1 = Tree(Oak, 10)