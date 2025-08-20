#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h> // لإضافة دالة tolower()

// تعريف النكت في مصفوفة لتسهيل إضافتها وتعديلها
const char* jokes[] = {
    "Why did the chicken cross the road? To get to the other side!",
    "I told my computer I needed a break, and it said, \"No problem, I'll go to sleep.\"",
    "I'm reading a book on anti-gravity. It's impossible to put down!",
    "Why don't scientists trust atoms? Because they make up everything!",
    "What do you call a fake noodle? An Impasta!"
};
// حساب عدد النكت تلقائياً
const int JOKE_COUNT = sizeof(jokes) / sizeof(jokes[0]);

// دالة أبسط لطباعة النكتة باستخدام رقمها
void printJoke(int index) {
    // طباعة النكتة من المصفوفة مباشرة
    printf("\nJoke #%d: %s\n\n", index + 1, jokes[index]);
}

int main(){
    // تهيئة مولد الأرقام العشوائية مرة واحدة فقط
    srand(time(NULL)); // تهيئة المولد العشوائي

    printf("--- Welcome to the Jokes Game! ---\n");
    printf("I know %d jokes. Let's have some fun!\n\n", JOKE_COUNT);

    while(1) { // استخدام حلقة while(1) القياسية
        int user_input;
        printf("Enter any number to get a random joke (or -1 to exit): ");

        // التحقق من أن المدخل رقم صحيح
        if (scanf("%d", &user_input) != 1) {
            printf("Invalid input. Please enter a number. Exiting.\n");
            // تنظيف مخزن الإدخال لتجنب حلقة لا نهائية
            while (getchar() != '\n');
            break;
        }

        if(user_input == -1){
            char choice;
            printf("Are you sure you want to exit? (y/n): ");
            scanf(" %c", &choice); // المسافة قبل %c مهمة لتجاهل أي محارف إضافية
            if(tolower(choice) == 'y'){
                printf("Goodbye! Hope you had a laugh!\n");
                break; // الخروج من الحلقة
            } else {
                printf("Great! Let's continue.\n\n");
                continue; // الاستمرار للحلقة التالية
            }
        }

        // توليد رقم عشوائي لاختيار نكتة
        int joke_index = rand() % JOKE_COUNT; // توليد قيمة عشوائية

        printJoke(joke_index);
    }

    return 0;
}
