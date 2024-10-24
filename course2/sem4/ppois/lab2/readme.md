# Лабораторная работа№2 #

## По курсу "Проектирование программного обеспечения интеллектуальных систем"(часть 2)

### Задание:

Разработать оконное приложение с одним главным окном и несколькими дочерними диалогами.
- Вызов диалогов осуществляется через соответствующие пункты меню.
- Приложение должно быть построено при помощи шаблона проектирования Model-View-Controller
- Сохранять и загружать массив записей из указываемого пользователем файла, посредством стандартного диалога сохранения/загрузки. 

### Вариант6:

Первоначальное окно с таблицей и панелью инструментов выглядит следующим образом:

![image](https://github.com/kvetkod/bsuir/assets/115100299/0ac5314e-938f-4201-9e57-f1da7b689d3c)

Таблица имеет 5 колонок: "Название товара", "Название производителя", "УПН производителя", "Количество" и "Адрес склада".

В панеле инструментов есть кнопки "Загрузить файл"(открывает файл, выбранный пользователем, если он имеется), "Сохранить файл"(сохраняет файл), "Добавить продукт"(открывает диалоговое окно для запиши элементов, которые добавятся в таблицу), "Поиск"(поиск элемента по ключу), "Удаление"(удаление элемента по ключу).

Также внизу файла имеется навигация по таблице, выборка количества элементов для отображения на одной странице, и быстрый переход на выбранную пользователем страницу.

#### Демонстрация работы программы

Окно "добавление продукта" выглядит следующим образов:

![image](https://github.com/kvetkod/bsuir/assets/115100299/af3dff50-650c-4633-b965-e3740ee96898)


Окно "поиска товара":

![image](https://github.com/kvetkod/bsuir/assets/115100299/7e205e52-0ed6-485c-82fe-7337bc796ead)


Поиск может осуществляться по всем критериям сразу либо выборочно. После результата поиска высвечивается таблица, а также появляется кнопка "Обновить", которая позволяет вернуться к первоначальному экрану.

![image](https://github.com/kvetkod/bsuir/assets/115100299/84c4727e-5a27-42c7-8727-411a4dce1545)



Окно удаления товара также, как и окно поиска, может происходить по одному или всем критериям сразу:

![image](https://github.com/kvetkod/bsuir/assets/115100299/9114e519-2180-41e4-a23e-1e60f1d12bfd)











