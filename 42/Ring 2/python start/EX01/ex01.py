class Plant:
    def __init__(self, name, height, age):
        self.name = name
        self.height = height
        self.age = age

    def info(self):
        return f"{self.name}: {self.height} cm, {self.age} days old"


if __name__ == "__main__":
    plant1 = Plant("Rose", 50, 30)
    plant2 = Plant("Sunflower", 150, 45)
    plant3 = Plant("Tulip", 30, 20)
    print("=== Garden Plant Registry ===")
    print(plant1.info())
    print(plant2.info())
    print(plant3.info())