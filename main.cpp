#include <iostream>
#include <vector>

#include <getopt.h>

std::vector<std::string>* h = new std::vector<std::string>();

void handleHelp()
{
    std::cout << "Option --help (-h) was used." << std::endl;
}

void handleTask(char *arg)
{
    std::cout << "Option --task (-t) with value " << arg << " was used." << std::endl;
}

void handlePostpone(char *arg)
{
    std::cout << "Option --postpone (-p) with value " << arg << " was used." << std::endl;
}

void handleInterval(char *arg)
{
    std::cout << "Option --interval (-i) with value " << arg << " was used." << std::endl;
}

bool isHandled(const std::string& n_option)
{
    for(auto &arg : *h)
    {
        if (n_option == arg)
        {
            return true;
        }
    }
    return false;
}

int main(int argc, char **argv)
{
    int c_option, i_option = 0;;

    const char* shorts = "ht:p:i:";

    struct option longs[] = {
            {"help",     no_argument, nullptr, 'h'},
            {"task",     required_argument, nullptr, 't'},
            {"postpone", required_argument, nullptr, 'p'},
            {"interval", required_argument, nullptr, 'i'},
            {nullptr, 0, nullptr, 0}
    };

    while((c_option = getopt_long(argc, argv, shorts, longs, &i_option)) != -1)
    {
        std::string n_option;

        for(struct option &e : longs)
        {
            if(e.val == c_option)
            {
                n_option = e.name;
                break;
            }
        }

        if(isHandled(n_option))
        {
            continue;
        }

        h->push_back(n_option);

        switch(c_option)
        {
            case 'h':
                handleHelp();
                break;

            case 't':
                handleFirst(optarg);
                break;

            case 'p':
                handleSecond(optarg);
                break;

            case 'i':
                handleDetailed(optarg);
                break;

            case '?':
                break;

            default:
                abort();
        }
    }

    if(optind < argc)
    {
        std::cout << "Non-option argument values:" << std::endl;
        while(optind < argc)
        {
            std::cout << argv[optind++] << std::endl;
        }
    }

    return 0;
}
