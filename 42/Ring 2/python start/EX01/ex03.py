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
    plant4 = Plant("Daisy", 25, 15)
    plant5 = Plant("Lily", 40, 25)
    print("=== Plant Factory Output ===")
    print("Created:" + plant1.info())
    print("Created:" + plant2.info())
    print("Created:" + plant3.info())
    print("Created:" + plant4.info())
    print("Created:" + plant5.info())
    print("\nTotal plants created: 5")