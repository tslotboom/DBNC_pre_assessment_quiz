import csv
import copy
from collections import OrderedDict
from typing import Dict


def getNumToStringDict() -> dict:
    """
    Create a dictionary mapping the number column to the string column in the input data
    :return: Dict mapping umber values to strings
    """
    numToStrDict = {}
    with open("q2.csv", "r") as csvfile:
        reader = csv.reader(csvfile, delimiter=',')
        for line in reader:
            numToStrDict[int(line[0])] = line[1].strip()
    return numToStrDict


def decimalToBase62(decimal: int) -> str:
    """
    Convert decimal number to base62
    :param decimal: decimal number
    :return: base62 number
    """
    base62 = ""
    while decimal > 0:
        remainder = decimal % 62
        decimal = decimal // 62
        base62 = symbols[remainder] + base62
    return base62


def encode(x: int, conversionTable: Dict[str, str]) -> str:
    """
    Convert decimal number to encoded base62 number which is a regular base62 number with values swapped based on the
    conversion table parameter
    :param x: decimal number to be encoded
    :param conversionTable: conversion table to convert regular base62 values to encoded base62 values
    :return: encoded base62 value
    """
    base62 = decimalToBase62(x)
    encoded = ""
    for i in base62:
        encoded += conversionTable[i]
    return encoded


if __name__ == "__main__":
    symbols = list("0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ")
    symbolsNotEncoded = copy.deepcopy(symbols)
    numToStringDict = getNumToStringDict()
    lookupTable = OrderedDict.fromkeys(symbols)

    # Build lookup table to create conversion between encoded base62 value and actual base62 value
    for num in numToStringDict.keys():
        encoded = numToStringDict[num]
        numBase62 = decimalToBase62(num)
        for i in range(len(encoded)):
            if numBase62[i] in symbolsNotEncoded:
                lookupTable[numBase62[i]] = encoded[i]
                symbolsNotEncoded.remove(numBase62[i])

    # The provided examples of encoded base62 values include all characters except for one. Therefore, we can look
    # through all values in the lookup table, find the one without a match yet and give it a partner. Only the second
    # case in this if statement will ever be triggered because of the input data, but in the spirit of good software
    # engineering I accounted for all cases.
    if len(symbolsNotEncoded) == 0:
        pass
    elif len(symbolsNotEncoded) == 1:
        for letter in lookupTable.keys():
            if lookupTable[letter] is None:
                lookupTable[letter] = symbolsNotEncoded.pop()
    else:
        raise RuntimeError("Unable to complete lookup table.")

    # Test to make sure that the created encoder is identical to the one used to generate the input data:
    for num in numToStringDict.keys():
        expectedEncoded = numToStringDict[num]
        actualEncoded = encode(num, lookupTable)
        if actualEncoded != expectedEncoded:
            raise RuntimeError(f"The encoded value of {num} {actualEncoded} doesn't match the expected value "
                               f"{expectedEncoded}")


    print("Q1a:")
    encodedLetters = ''.join(lookupTable.values())
    print(f"Encoded base62 values: {encodedLetters}")

    print("Q2b:")
    print(f"f(30001) = {encode(30001, lookupTable)}")
    print(f"f(55555) = {encode(55555, lookupTable)}")
    print(f"f(77788) = {encode(77788, lookupTable)}")
