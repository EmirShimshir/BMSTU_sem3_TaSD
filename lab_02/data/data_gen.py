from random import *

# Ввести список стран, в которых можно отдохнуть, содержащий
# название страны, количество жителей, столицу, материк,
# нужна ли прививка или ПЦР, основной вид туризма
# (экскурсионный - количество объектов, основной вид (природа,
# история, искусство); пляжный – основной сезон, температура
# воздуха и воды, время полета до страны; спортивный – вид
# спорта (горные лыжи, серфинг, восхождения), минимальная
# стоимость отдыха,). Вывести список стран на выбранном
# материке, где можно заняться указанным видом спорта.

country = ("Russia", "Belarus", "Ukraine", "China", "Bulgary", "Germany", "Japan", "Britain", "USA", "Australia", "Georgia")

capital = ("Chelyabinsk", "Moscow", "Belgorod", "Humburg", "Minsk", "Honkong", "London", "Seul", "Colorado", "Zavolzhye", "Sochi", "Odessa")
mainland = ("Africa", "Asia", "Europe", "North_America", "South_America", "Antarctica", "Oceania")
tourism = ("Excursion", "Beach", "Sport")
excursion_type = ("Nature", "History", "Art")
beach_type = ("Summer", "Winter", "Autumn", "Spring")
sport_type = ("Skiing", "Surfing", "Climb")

# Страна Население Столица Материк ПЦР Вид туризма ... ... ... ...

file = open("countries_50.txt", "w")
for i in range(50):
    file.write(country[randint(0, 10)])
    file.write(' ')
    file.write(str(randint(1000, 10000000)))  # Население
    file.write(' ')
    file.write(capital[randint(0, 11)])
    file.write(' ')
    file.write(mainland[randint(0, 6)])
    file.write(' ')
    file.write(str(randint(0, 1)))  # ПЦР
    file.write(' ')

    tour = tourism[randint(0, 2)]  # Вид туризма
    file.write(tour)
    file.write(' ')

    if tour == "Excursion":
        file.write(str(randint(0, 100)))  # Кол-во объектов
        file.write(' ')
        file.write(excursion_type[randint(0, 2)])  # Основной вид
        file.write(' ')
    elif tour == "Beach":
        file.write(beach_type[randint(0, 3)])  # Основной сезон
        file.write(' ')
        file.write(str(randint(-30, 40)))  # Температура воздуха
        file.write(' ')
        file.write(str(randint(0, 30)))  # Температура воды
        file.write(' ')
        file.write(str(randint(0, 12 * 60)))  # Время полёта
        file.write(' ')
        pass
    elif tour == "Sport":
        # вид спорта (горные лыжи, серфинг, восхождения), минимальная
        # стоимость отдыха)
        file.write(sport_type[randint(0, 2)])  # Вид спорта
        file.write(' ')
        file.write(str(randint(0, 1000000)))  # Стоимость отдыха
        file.write(' ')
        pass

    file.write("\n")

file.close()