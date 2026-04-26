#include <iostream>
#include <cstdio>

int main() {
    int num = 67;

    printf("%-15s | %-10s\n", "Integer", "formats:");
    printf("%-15s | %-10d\n", "Decimal", num);
    printf("%-15s | %-10x\n", "Hexadecimal", num);
    printf("%-15s | %-10o\n", "Octal", num); 

    float natural_e = 2.71828;
    printf("%-15s | %-10s\n", "Float", "formats:");
    printf("%-15s | %-10.2f\n", "Precision of (2)", natural_e);
    printf("%-15s | %-10e\n", "Scientific", natural_e);
    printf("%-15s | %-10.4f\n", "Fixed with precision (4)", natural_e);
    
    char c = 'M';
    const char* string_value = "Hello, World!";
    printf("%-15s | %-10s | %-10s\n", "Character", "and String", "formats:");
    printf("%-15s | %-10c\n", "Character:", c);
    printf("%-15s | %-10s\n", "String:", string_value);
    
    return 0;

}