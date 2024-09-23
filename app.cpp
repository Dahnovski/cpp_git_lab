#include <iostream>
#include <regex>
#include <string>
#include <vector>

#define         EXIT__SUCCESS           0

// Класс для извлечения марок автомобилей
class CarBrandExtractor {
public:
    // Метод для извлечения марок автомобилей
    std::vector<std::string> extractBrands(const std::string& text) {
        std::vector<std::string> brands;
        std::regex brandRegex(R"((Mercedes|BMW|Audi|Toyota|Ford))");
        std::smatch match;
        std::string::const_iterator searchStart(text.cbegin());
        
        while (std::regex_search(searchStart, text.cend(), match, brandRegex)) {
            brands.push_back(match[0]);
            searchStart = match.suffix().first;
        }
        return brands;
    }
};

// Класс для извлечения моделей автомобилей
class CarModelExtractor {
public:
    // Метод для извлечения моделей автомобилей
    std::vector<std::string> extractModels(const std::string& text) {
        std::vector<std::string> models;
        std::regex modelRegex(R"((A4|C-Class|Mustang|Camry|Corolla))");
        std::smatch match;
        std::string::const_iterator searchStart(text.cbegin());
        
        while (std::regex_search(searchStart, text.cend(), match, modelRegex)) {
            models.push_back(match[0]);
            searchStart = match.suffix().first;
        }
        return models;
    }
};

// Основной класс для управления извлечением
class CarInfoExtractor {
private:
    CarBrandExtractor brandExtractor;
    CarModelExtractor modelExtractor;

public:
    void extractCarInfo(const std::string& text) {
        // Извлечение марок автомобилей
        std::vector<std::string> brands = brandExtractor.extractBrands(text);
        // Извлечение моделей автомобилей
        std::vector<std::string> models = modelExtractor.extractModels(text);

        // Вывод результатов
        std::cout << "Found car brands: ";
        for (const auto& brand : brands) {
            std::cout << brand << " ";
        }
        std::cout << std::endl;

        std::cout << "Found car models: ";
        for (const auto& model : models) {
            std::cout << model << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
        std::string text = "I saw a Mercedes C-Class and a Ford Mustang on the road. My friend drives a Toyota Camry.";
        
	CarInfoExtractor carInfoExtractor;
    
    	// Извлекаем информацию о марках и моделях автомобилей
    	carInfoExtractor.extractCarInfo(text);

        return EXIT__SUCCESS;
}
