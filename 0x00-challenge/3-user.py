#!/usr/bin/python3

import hashlib
import uuid


class User():
    """
    Represents a user with an ID and a password.

    Attributes:
        id (str): A unique identifier for the user.
        __password (str): A hashed representation of the user's password.
    """

    def __init__(self):
        """
        Initializes a new user with a unique ID.
        """
        self.id = str(uuid.uuid4())
        self.__password = None

    @property
    def password(self):
        """
        Getter method for the user's password.

        Returns:
            str: The hashed representation of the user's password.
        """
        return self.__password

    @password.setter
    def password(self, pwd):
        """
        Setter method for the user's password.
        Hashes the provided password before storing it.

        Args:
            pwd (str): The password to be hashed and set for the user.
        """
        if pwd is None or type(pwd) is not str:
            self.__password = None
        else:
            self.__password = hashlib.md5(pwd.encode()).hexdigest().lower()

    def is_valid_password(self, pwd):
        """
        Checks if the provided password matches the user's hashed password.

        Args:
            pwd (str): The password to be validated.

        Returns:
            bool: True if the provided password matches the user's hashed
            password, False otherwise.
        """
        if pwd is None or type(pwd) is not str:
            return False
        if self.password is None:
            return False
        return hashlib.md5(pwd.encode()).hexdigest().lower() == self.password

if __name__ == '__main__':
    # Test cases
    print("Test User")

    user_1 = User()
    if user_1.id is None:
        print("New User should have an id")

    user_2 = User()
    if user_1.id == user_2.id:
        print("User.id should be unique")

    u_pwd = "myPassword"
    user_1.password = u_pwd
    if user_1.password == u_pwd:
        print("User.password should be hashed")

    if user_2.password is not None:
        print("User.password should be None by default")

    user_2.password = None
    if user_2.password is not None:
        print("User.password should be None if setter to None")

    user_2.password = 89
    if user_2.password is not None:
        print("User.password should be None if setter to an integer")

    if not user_1.is_valid_password(u_pwd):
        print("is_valid_password should return True if it's the right password")

    if user_1.is_valid_password("Fakepwd"):
        print("is_valid_password should return False if it's not the right password")

    if user_1.is_valid_password(None):
        print("is_valid_password should return False if compare with None")

    if user_1.is_valid_password(89):
        print("is_valid_password should return False if compare with integer")

    if user_2.is_valid_password("No pwd"):
        print("is_valid_password should return False if no password set before")
