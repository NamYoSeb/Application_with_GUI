# Название
Tower Defence
# Участники:
1. Птухов Денис
2. Нам Ё Себ
3. Самакаев Дмитрий
4. Cани Заяд
# Описание игры
Игра состоит из нескольких уровней, главной целью на которых является защита базы от противников, с помощью постройки оборонительных сооружений.
### Описание механик игры
Задачей игрока является защита базы от врагов. Игровое поле разделено на сетку из пяти горизонтальных рядов и девяти столбцов. Игрок размещает различные типы строений на отдельных клетках сетки. Каждое строение имеет свою уникальную способность. Некоторые типы врагов также имеют свои способности, вследствие чего некоторые строения могут быть более эффективны против конкретных из них. Перед началом каждого уровня игрок выбирает только определённый набор строений и по мере прохождения уровня должен тратить определённое количество единиц ресурсов для того чтобы построить новое строение. Единицы ресурса генерируется автоматически, а также выдаются определёнными строениями. Если противник достигнет конца дорожки уровень будет проигран.
# Пользовательское взаимодействие
Единственный пользователь – игрок. Игроку на выбор дается 2 режима игры – кампания и выживание. В режиме кампании игрок проходит заранее сгенерированные уровни. В режиме выживания игрок проходит уровень с бесконечно генерируемыми волнами противников. Пользователь может посмотреть свою статистику по играм.
### Сценарии использования
* Однопользовательская игра
* Просмотр статистики игр
# Основные задачи
* Реализовать одиночную игру
* Разработать удобный графический интерфейс
* Обеспечить кроссплатформенность игры 
# Архитектура приложения
![](https://github.com/NamYoSeb/Application_with_GUI/blob/main/UML.jpg?raw=true)

# Первая итерация
### Поставленные задачи
Разработать прототип графического интерфейса программы и проработать основные механики игры.
### Сценарии использования
При запуске приложения пользователь вводит свое имя и выбирает уровень. Во время игры пользователь может выбрать определнные типы сооружений и разместить их на игровом поле. 
### Демонстрация работы
https://drive.google.com/file/d/1o2gsEyJ_i0FwQ1wbVmlU8y39g02WmpUE/view?usp=sharing

# Вторая итерация
### Поставленные задачи
Ввести сущности юнитов-союзников и юнитов-противников(включая атрибуты, такие как здоровье, урон...), доработать основные механики(перемещение юнитов-противников, взаимодействие юнитов между собой).
### Сценарии использования
После начала игры на поле начинают появляться юниты-противники, игрок ставит на поле юнитов-союзников. Противники наступают на базу игрока, сталкиваясь с юнитами-союзниками, атакуют их.
### Демонстрация работы
https://drive.google.com/file/d/1BYQdpFKnC3RzAz6ZJm3I_gFfUBxMugJg/view?usp=sharing

# Третья итерация
### Поставленные задачи
Внедрить в проект взаимодействие между союзными юнитами и юнитами противника, создание игровой экономики. Союзные юниты воздействуют на юнитов противников при помощи специальных объектов "пуль", при столкновении юниты противники начинают атаковать союзных юнитов, соотвественно, для каждого объекта будут заданы такие параметры как: здоровье, атака, скорость атаки и т.д. 
### Сценарии использования
После начала игры на поле начинают появляться юниты-противники, игрок ставит на поле юнитов-союзников. Противники наступают на базу игрока, сталкиваясь с юнитами-союзниками, атакуют их.

### Распределение обязанностей 
1. Птухов Денис - взаимодейсвтие объектов 
2. Самакаев Дмитрий - "пули"
3. Нам Ё Себ - игровая экономика
4. Сани Заяд - задание параметров юнитов

### Демонстрация работы
https://drive.google.com/file/d/1pJ2sLYyhc6bLVQs24DQw9WqcXJ7kgtu9/view?usp=sharing
