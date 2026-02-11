class Plant:
    def __init__(self, name, height, age):
        self.name = name
        self.height = height
        self.age = age

    def info(self):
        return f"{self.name}: {self.height} cm, {self.age} days old"

    def grew(self, cm):
        self.height += cm

    def aged(self, days):
        self.age += days


if __name__ == "__main__":
    plant1 = Plant("Rose", 50, 30)
    initial_height = plant1.height
    print("=== Day 1 ===")
    print("Before growing:", plant1.info())

    for _ in range(6):
        plant1.grew(1)
        plant1.aged(1)
    print("=== Day 7 ===")
    print("After growing:", plant1.info())
    print(f"Growth this week: +{plant1.height - initial_height}cm")
