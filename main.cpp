#include "questions/appleColor.h"
#include "questions/buildTree.h"
#include "questions/snippets.h"
#include "questions/securityLevel.h"
#include "questions/catColor.h"
#include "questions/redTea.h"
#include "questions/binarySearch.h"
#include "questions/stack.h"
#include "questions/transportation.h"
#include "questions/mathVector.h"
#include "questions/complexNumber.h"
#include "questions/fibonacciN.h"

enum QList {
    snippet,
    buildTree,
    binarySearch,
    appleColor,
    securityLevel,
    catColor,
    redTea,
    stack,
    transportation,
    mathVector,
    complexNumber,
    fibonacciN,
};

class Questions {

public:

    void showAnswers(QList select) {

        switch (select) {

            case QList::snippet:
//            execute_snippets();
                execute_snippets_108();
//                execute_snippets_110();
                break;

            case QList::buildTree: {
                nodep_t root = nullptr;
                auto *bt = new BuildTree();

                int array[] = {23, 12, 43, 21, 65, 3, 2};
                for (int i: array) {
                    root = bt->insert(root, i);
                }

                bt->inorder_transversal(root);
                printf("\n");
                bt->postorder_traversal(root);
                printf("\n");
                bt->preorder_traversal(root);

                delete bt;
            }
                break;

            case QList::appleColor: {

                Apple apple;
                apple.setCultivar("McIntosh", "green");

                Fruit *p1 = new Apple();
                Fruit *p2 = new Apple(apple);
                Apple *p3 = new Apple();

                p3->setColor("yellow");
                p3->setCultivar("McIntosh");
                p1->printInfo();
                p2->printInfo();
                p3->printInfo();
                p1->printData();
                p2->printData();
                p3->printData();

                delete p1, p2, p3;
            }
                break;

            case QList::securityLevel: {
                execute_security_level();
            }
                break;

            case QList::catColor: {

                Animal *p1 = new Cat("black");
                Cat *p2 = new Cat();
                Cat cat = Cat("silver") + *p2;
                cout << cat.getColor() << endl;

                p1->makeSound();
                p1->food();
                p2->makeSound();
                p2->food();
            }
                break;

            case QList::redTea: {

                Order order;
                order.append_alcohol(NewBloodyMary::CreateNewBloodyMaryPtr("A", 870, 0.7));
                order.append_alcohol(new LongIsland("B", 230, 0.7));
                vector<RedTea *> alcohol_vec = {
                        new LongIsland("C", 77, 0.7),
                        NewBloodyMary::CreateNewBloodyMaryPtr("D", 88, 0.8),
                        NewBloodyMary::CreateNewBloodyMaryPtr("E", 12, 0.8)
                };

                std::sort(alcohol_vec.begin(), alcohol_vec.end(), [](RedTea *a, RedTea *b) {
                    return a->get_price() < b->get_price();
                });

                NewBloodyMary H = CreateNewBloodyMary("F", 90, 0.8) + CreateNewBloodyMary("G", 10, 0.8);

                cout << alcohol_vec.at(0)->get_price() << endl;
                cout << alcohol_vec.at(1)->get_price() << endl;
                cout << order.get_total_price() << endl;
                cout << H.get_name() << endl;
                cout << H.get_price() << endl;
                cout << H.get_alcohol_content() << endl;

            }
                break;

            case QList::binarySearch: {

                vector<int> numbers;

                numbers.reserve(50);
                for (int i = 0; i < 50; i++) {
                    numbers.push_back(random() % 200);
                }

                sort(numbers.begin(), numbers.end());

                for (int i = 0; i <= numbers.size(); i++) {
                    if (i % 10 == 0) cout << endl;
                    cout << numbers[i] << "  ";
                }

                int idx = bsearch(numbers, 29, 0, (int) numbers.size());

                cout << endl << "The Index:" << idx << endl;
                cout << "Actual: " << numbers[idx];

            }

            case QList::stack: {

                execute_stack_110();
            }

            case QList::transportation: {

                execute_transportation();
            }

            case QList::mathVector: {

                execute_math_vector();
            }

            case QList::complexNumber: {

                execute_complex_number();
            }

            case QList::fibonacciN: {

                execute_fibonacci_n();
            }
        }
    }
};


int main() {

    auto *q = new Questions();
    q->showAnswers(QList::fibonacciN);

    delete q;
    return EXIT_SUCCESS;
}