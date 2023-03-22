class Restaurant:
    def __init__(self,restaurant_name,cuisine_name):
        self.restaurant_name=restaurant_name
        self.cuisine_name=cuisine_name
    def describe_restaurant(self):
        print("the restaurant name is "+str(self.restaurant_name));
        print("the cuisine type is "+str(self.cuisine_name));
    def open_restaurant(self):
        print("the restaurant is open");


restaurant=Restaurant("Breaking_kitchen","seafood");
restaurant.describe_restaurant();
restaurant.open_restaurant();
