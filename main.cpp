#include <locale>
#include <iostream>
#include <limits>

int main() {
    std::setlocale(LC_ALL, "Russian"); 

    double a, b;
    char op;

    std::cout << "Калькулятор (введите выражение: число оператор число)\n";
    std::cout << "Пример: 5 + 3\n";
    std::cout << "Операторы: -, +, *, /\n";

    while (true) {
        std::cout << "> ";
        
        // Проверка на корректный ввод
        if (!(std::cin >> a >> op >> b)) {
            std::cin.clear(); // Сброс флага ошибки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка буфера
            std::cout << "Ошибка ввода. Попробуйте снова.\n";
            continue;
        }

        double result = 0.0;
        bool ok = true;

        switch (op) {
            case '+': 
                result = a + b; 
                break;
            case '-': 
                result = a - b; 
                break;
            case '*': 
                result = a * b; 
                break;
            case '/':
                if (b == 0) {
                    std::cout << "Ошибка: деление на ноль!\n";
                    ok = false;
                } else {
                    result = a / b;
                }
                break;
            default:
                std::cout << "Неизвестный оператор: " << op << "\n";
                ok = false;
        }

        if (ok) {
            std::cout << "Результат: " << result << "\n";
        }
    }

    return 0;
}
