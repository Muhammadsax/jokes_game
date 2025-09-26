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
    "What do you call a fake noodle? An Impasta!",
    "Why did the scarecrow win an award? Because he was outstanding in his field.",
    "What do you call a fish with no eyes? Fsh.",
    "I used to play piano by ear, but now I use my hands.",
    "Why don't skeletons fight each other? They don't have the guts.",
    "What do you get when you cross a snowman and a vampire? Frostbite.",
    "I'm on a seafood diet. I see food and I eat it.",
    "Why did the bicycle fall over? Because it was two-tired.",
    "What do you call a bear with no teeth? A gummy bear.",
    "How do you organize a space party? You planet.",
    "Why was the math book sad? Because it had too many problems.",
    "What do you call a lazy kangaroo? Pouch potato.",
    "I would tell you a joke about an elevator, but it's an uplifting story.",
    "Why did the coffee file a police report? It got mugged.",
    "What's orange and sounds like a parrot? A carrot.",
    "I have a joke about construction, but I'm still working on it.",
    "Why can't a bicycle stand up by itself? It's two-tired.",
    "What do you call a dog that does magic tricks? A labracadabrador.",
    "Why did the tomato turn red? Because it saw the salad dressing.",
    "I don't trust stairs. They're always up to something.",
    "What do you call a belt made out of watches? A waist of time.",
    "Why did the golfer bring two pairs of pants? In case he got a hole in one.",
    "What's a vampire's favorite fruit? A neck-tarine.",
    "Why do we tell actors to 'break a leg?' Because every play has a cast.",
    "Helvetica and Times New Roman walk into a bar. 'Get out of here!' shouts the bartender. 'We don't serve your type.'",
    "Did you hear about the restaurant on the moon? Great food, no atmosphere.",
    "What do you call a can opener that doesn't work? A can't opener.",
    "I'm so good at sleeping, I can do it with my eyes closed.",
    "Why did the scarecrow get a promotion? He was outstanding in his field.",
    "What do you call a pile of cats? A meowtain.",
    "Why don't some couples go to the gym? Because some relationships don't work out.",
    "I told my wife she was drawing her eyebrows too high. She looked surprised.",
    "What do you call a factory that makes okay products? A satisfactory.",
    "What's the best thing about Switzerland? I don't know, but the flag is a big plus.",
    "Why did the invisible man turn down the job offer? He couldn't see himself doing it.",
    "I invented a new word! Plagiarism!",
    "Did you hear about the claustrophobic astronaut? He just needed a little space.",
    "Why don't eggs tell jokes? They'd crack each other up.",
    "What do you call a sad strawberry? A blueberry.",
    "Why was the cookie sad? Because its mom was a wafer so long.",
    "What do you call a boomerang that won't come back? A stick.",
    "Why did the student eat his homework? Because the teacher told him it was a piece of cake.",
    "What do you call a man with a rubber toe? Roberto.",
    "Why did the chewing gum cross the road? It was stuck to the chicken's foot.",
    "What do you call an alligator in a vest? An investigator.",
    "Why do bees have sticky hair? Because they use honeycombs.",
    "What do you call a lazy-eyed dinosaur? A Doyouthinkhesaurus.",
    "How does a penguin build its house? Igloos it together.",
    "Why did the scarecrow become a successful neurosurgeon? He was outstanding in his field.",
    "What do you call a cheese that isn't yours? Nacho cheese.",
    "Why did the music teacher need a ladder? To reach the high notes.",
    "What do you call a sleeping bull? A bulldozer.",
    "Why did the man get fired from the calendar factory? He took a couple of days off.",
    "I have a fear of speed bumps, but I'm slowly getting over it.",
    "What do you call a fish wearing a bowtie? Sofishticated.",
    "Why did the computer go to the doctor? It had a virus.",
    "What do you call a group of musical whales? An orca-stra.",
    "Why did the skeleton go to the party alone? He had no body to go with.",
    "What do you call a psychic little person escaping from prison? A small medium at large.",
    "Why don't programmers like nature? It has too many bugs.",
    "What do you call a cow with no legs? Ground beef.",
    "Why did the man put his money in the freezer? He wanted cold hard cash.",
    "What do you call a story about a broken pencil? Pointless.",
    "Why did the gym close down? It just didn't work out.",
    "What do you call a line of men waiting for a haircut? A barber-queue.",
    "Why did the picture go to jail? It was framed.",
    "What do you call a magic dog? A labracadabrador.",
    "Why did the mushroom go to the party? Because he was a fungi.",
    "What do you call a pig that does karate? A pork chop.",
    "Why did the phone wear glasses? It lost its contacts.",
    "What do you call a thieving alligator? A crook-o-dile.",
    "Why did the tree go to the dentist? It needed a root canal.",
    "What do you call a writer named Will? A Shakespeare.",
    "Why did the woman run around her bed? To catch up on her sleep.",
    "What do you call a zoo that only has one dog? A shih tzu.",
    "Why did the coffee taste like mud? Because it was ground a few minutes ago.",
    "What do you call a dinosaur with an extensive vocabulary? A thesaurus.",
    "Why did the ocean roar? You would too if you had crabs on your bottom.",
    "What do you call a person who is happy on Monday? Retired.",
    "Why did the police arrest the turkey? They suspected it of fowl play.",
    "What do you call a programmer from Finland? A Nerdic.",
    "Why did the scarecrow's friend move away? He was tired of being a straw man.",
    "What do you call a sheep with no legs? A cloud.",
    "Why did the student get an F on his report card? Because he was below C-level.",
    "What do you call a teacher who is always late? A slow-learner.",
    "Why did the toilet paper roll down the hill? To get to the bottom.",
    "What do you call a turtle who takes up photography? A snapping turtle.",
    "Why did the vampire get a job at the blood bank? He wanted to work with his own kind.",
    "What do you call a vegetarian with diarrhea? A salad shooter.",
    "Why did the whale cross the ocean? To get to the other tide.",
    "What do you call a window that lies? A pane-in-the-glass.",
    "Why did the woman wear a helmet at the dinner table? She was on a crash diet.",
    "What do you call a worm that is 100 meters long? A beltworm.",
    "Why did the zombie go to the library? He wanted to read a book about brains.",
    "What do you call a lazy person's favorite food? Couch potatoes.",
    "Why did the sun go to school? To get brighter."
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
