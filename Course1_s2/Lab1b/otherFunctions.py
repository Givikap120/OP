def productDict():
    product = {"name":"",
               "type":"",
               "color":"",
               "price":0.0,
               "quantity":0}
    return product

def printProduct(product):
    print("Product name - " + product["name"])
    print("Type - " + product["type"])
    print("Color - " + product["color"])
    print("Price - " + str(product["price"]))
    print("Quantity - " + str(product["quantity"]) + '\n')

def printDB(database):
    for i in range(len(database)):
        printProduct(database[i])

def keyFilter(database, key ,key_filter):
    i = 0
    while i < len(database):
        if database[i][key] != key_filter:
            database.pop(i)
            i-=1
        i+=1
    return database

def deleteByKeyRange(database, key, min_key, max_key):
    i = 0
    while i < len(database):
        if database[i][key] >= min_key and database[i][key] <= max_key:
            database.pop(i)
            i-=1
        i+=1
    return database



    
