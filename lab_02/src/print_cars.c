#include <stdio.h>

#include "my_string.h"
#include "print_cars.h"
#include "cars.h"

void print_column_line(const int line_len)
{
    for (size_t j = 0; j < line_len; j++)
        printf("─");
}

void print_str(const char *const str, const int max_len)
{
    printf("%s", str);

    unsigned short int space_num = max_len - my_strlen(str);

    for (unsigned short int i = 0; i < space_num; i++)
        printf(" ");
}

void print_header(void)
{
    printf("┌");

    print_column_line(MAX_BRAND_LEN / 2);
    printf("┬");

    print_column_line(MAX_COUNTRY_LEN / 2);
    printf("┬");

    print_column_line(MAX_COLOR_LEN / 2);
    printf("┬");

    print_column_line(MAX_PRICE_LEN);
    printf("┬");

    print_column_line(MAX_CONDITION_LEN + 5);
    printf("┬");

    print_column_line(MAX_WARRANTY_LEN + 6);
    printf("┬");

    print_column_line(MAX_YEAR_LEN + 3);
    printf("┬");

    print_column_line(MAX_MILEAGE_LEN);
    printf("┬");

    print_column_line(MAX_REPAIRS_NUM_LEN + 5);
    printf("┬");

    print_column_line(MAX_OWNERS_NUM_LEN + 10);
    printf("┐");

    puts("");

    printf("│");
    print_str("     Марка", MAX_BRAND_LEN / 2);

    printf("│");
    print_str("Страна-производитель", MAX_COUNTRY_LEN / 2);

    printf("│");
    print_str("     Цвет", MAX_COLOR_LEN / 2);

    printf("│");
    print_str("   Цена,", MAX_PRICE_LEN);

    printf("│");
    print_str("Состояние", MAX_CONDITION_LEN + 5);

    printf("│");
    print_str("Гарантия,", MAX_WARRANTY_LEN + 6);

    printf("│");
    print_str("  Год", MAX_YEAR_LEN + 3);
    
    printf("│");
    print_str("Пробег,", MAX_MILEAGE_LEN);
    
    printf("│");
    print_str(" Кол-во", MAX_REPAIRS_NUM_LEN + 5);
    
    printf("│");
    print_str("    Кол-во", MAX_OWNERS_NUM_LEN + 10);
    
    printf("│");
    puts("");

    printf("│");
    print_str("", MAX_BRAND_LEN / 2);

    printf("│");
    print_str("", MAX_COUNTRY_LEN / 2);

    printf("│");
    print_str("", MAX_COLOR_LEN / 2);

    printf("│");
    print_str("  тыс руб", MAX_PRICE_LEN);

    printf("│");
    print_str("", MAX_CONDITION_LEN + 5);

    printf("│");
    print_str("   лет", MAX_WARRANTY_LEN + 6);

    printf("│");
    print_str("выпуска", MAX_YEAR_LEN + 3);

    printf("│");
    print_str("  км", MAX_MILEAGE_LEN);

    printf("│");
    print_str("ремонтов", MAX_REPAIRS_NUM_LEN + 5);
    
    printf("│");
    print_str("собственников", MAX_OWNERS_NUM_LEN + 10);
    
    printf("│");
    puts("");

    printf("├");

    print_column_line(MAX_BRAND_LEN / 2);
    printf("┼");

    print_column_line(MAX_COUNTRY_LEN / 2);
    printf("┼");

    print_column_line(MAX_COLOR_LEN / 2);
    printf("┼");

    print_column_line(MAX_PRICE_LEN);
    printf("┼");

    print_column_line(MAX_CONDITION_LEN + 5);
    printf("┼");

    print_column_line(MAX_WARRANTY_LEN + 6);
    printf("┼");

    print_column_line(MAX_YEAR_LEN + 3);
    printf("┼");

    print_column_line(MAX_MILEAGE_LEN);
    printf("┼");

    print_column_line(MAX_REPAIRS_NUM_LEN + 5);
    printf("┼");

    print_column_line(MAX_OWNERS_NUM_LEN + 10);
    printf("┤");

    puts("");
}

void print_down_line(void)
{
    printf("└");

    print_column_line(MAX_BRAND_LEN / 2);
    printf("┴");

    print_column_line(MAX_COUNTRY_LEN / 2);
    printf("┴");

    print_column_line(MAX_COLOR_LEN / 2);
    printf("┴");

    print_column_line(MAX_PRICE_LEN);
    printf("┴");

    print_column_line(MAX_CONDITION_LEN + 5);
    printf("┴");

    print_column_line(MAX_WARRANTY_LEN + 6);
    printf("┴");

    print_column_line(MAX_YEAR_LEN + 3);
    printf("┴");

    print_column_line(MAX_MILEAGE_LEN);
    printf("┴");

    print_column_line(MAX_REPAIRS_NUM_LEN + 5);
    printf("┴");

    print_column_line(MAX_OWNERS_NUM_LEN + 10);
    printf("┘");

    puts("");

}

void print_record(const car_t *const record)
{
    printf("│");
    print_str(record->brand, MAX_BRAND_LEN / 2);

    printf("│");
    print_str(record->country, MAX_COUNTRY_LEN / 2);

    printf("│");
    print_str(record->color, MAX_COLOR_LEN / 2);

    printf("│%*d", MAX_PRICE_LEN, record->price);

    printf("│");
    if (NEW == record->condition)
    {
        print_str("новый", MAX_CONDITION_LEN + 5);

        printf("│%*d", MAX_WARRANTY_LEN + 6, record->more_info.new_car.warranty);

        printf("│");
        print_str("   --", MAX_YEAR_LEN + 3);
        
        printf("│");
        print_str("   --", MAX_MILEAGE_LEN);
        
        printf("│");
        print_str("   --", MAX_REPAIRS_NUM_LEN + 5);
        
        printf("│");
        print_str("      --", MAX_OWNERS_NUM_LEN + 10);
    }
    else
    {
        print_str("б/у", MAX_CONDITION_LEN + 5);

        printf("│");
        print_str("    --", MAX_WARRANTY_LEN + 6);

        printf("│%*d", MAX_YEAR_LEN + 3, record->more_info.used_car.year);
        
        printf("│%*d", MAX_MILEAGE_LEN, record->more_info.used_car.mileage);
        
        printf("│%*d", MAX_REPAIRS_NUM_LEN + 5, record->more_info.used_car.repairs_num);
        
        printf("│%*d", MAX_OWNERS_NUM_LEN + 10, record->more_info.used_car.owners_num);
    }

    printf("│");
    puts("");
}

void print_cars(car_table_t *table)
{
    if (table->len)
    {
        print_header();

        for (size_t i = 0; i < table->len; i++)
            print_record(&table->table[i]);

        print_down_line();
    }
    else
    {
        puts("");
        puts("В таблице нет данных!");
    }
}

void print_key_header(void)
{
    printf("┌");

    print_column_line(14);
    printf("┬");

    print_column_line(MAX_PRICE_LEN);
    printf("┐");

    puts("");

    printf("│");
    print_str(" № в исходной", 14);

    printf("│");
    print_str("   Цена,", MAX_PRICE_LEN);

    printf("│");
    puts("");

    printf("│");
    print_str("    таблице", 14);

    printf("│");
    print_str("  тыс руб", MAX_PRICE_LEN);
    
    printf("│");
    puts("");

    printf("├");

    print_column_line(14);
    printf("┼");

    print_column_line(MAX_PRICE_LEN);
    printf("┤");

    puts("");
}

void print_key_record(const car_key_t *const record)
{
    printf("│%*ld", 14, record->num);

    printf("│%*d", MAX_PRICE_LEN, record->price);

    printf("│");
    puts("");
}

void print_key_down_line(void)
{
    printf("└");

    print_column_line(14);
    printf("┴");

    print_column_line(MAX_PRICE_LEN);
    printf("┘");

    puts("");
}

void print_cars_keys(car_key_table_t *table)
{
    if (table->len)
    {
        print_key_header();

        for (size_t i = 0; i < table->len; i++)
            print_key_record(&table->table[i]);

        print_key_down_line();
    }
    else
    {
        puts("");
        puts("В таблице нет данных!");
    }
}

void print_cars_by_keys(car_table_t *table, car_key_table_t *keys)
{
    if (table->len)
    {
        print_header();

        for (size_t i = 0; i < table->len; i++)
            print_record(&table->table[keys->table[i].num]);

        print_down_line();
    }
    else
    {
        puts("");
        puts("В таблице нет данных!");
    }
}