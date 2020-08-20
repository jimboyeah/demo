<!DOCTYPE html>
<html xmlns:th="http://www.thymeleaf.org">
<html>
    <head>
        <title>Home page</title>
        <meta charset="UTF-8">
    </head>
    <body>
        <p>Hello ${name}, this is FreeMarker!</p>
        <p th:text="'Hello, ' + ${name}" />th:text -> Hello ${name}, this is Thymeleaf!</p>
    </body>
</html>