class SecurePlant:
    def __init__(self, name, height, age):
        self.name = name
        self.__height = height
        self.__age = age
        print(f"Plant created: {self.name}")

    def info(self):
        print(f"{self.name}: {self.__height} cm, {self.__age} days old")

    def grew(self, cm):
        self.__height += cm

    def aged(self, days):
        self.__age += days

    def set_height(self, __height):
        if __height >= 0:
            self.__height = __height
            print(f"height updated: {self.__height} cm [ok]")
        else:
            print(f"\nInvalid operation attempted: {__height} cm [REJECTED]")
            print("Security: Negative height rejected\n")

    def set_age(self, __age):
        if __age >= 0:
            self.__age = __age
            print(f"age updated: {self.__age} days [ok]")
        else:
            print(f"\nInvalid operation attempted: {__age} days [REJECTED]")
            print("Security: Negative age rejected\n")

    def get_height(self):
        print(self.__height)

    def get_age(self):
        print(self.__age)


if __name__ == "__main__":
    print("=== Garden Security System ===")
    plant1 = SecurePlant("Rose", 0, 0)
    plant1.set_height(25)
    plant1.set_age(30)
    plant1.set_height(-5)
    plant1.info()
