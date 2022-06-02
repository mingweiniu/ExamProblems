# 1603. Design Parking System

class ParkingSystem:

    def __init__(self, big: int, medium: int, small: int):
        self.space = [0 , big, medium, small]        

    def addCar(self, carType: int) -> bool:
        self.space[carType] -= 1
        return 0 <= self.space[carType]