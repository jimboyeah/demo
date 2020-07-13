#include <iostream>
#include <iterator>
#include <string>
#include <regex>
 
int main()
{
    std::string s = "Some people, when confronted with a problem, think "
        "\"I know, I'll use regular expressions.\" "
        "Now they have two problems.";

    std::string UP = "REGULAR EXPRESSIONS";
    std::regex self_regex(UP.c_str(),
        std::regex_constants::ECMAScript | std::regex_constants::icase);

    if (std::regex_search(s, self_regex))
    {
        std::cout << UP << " Found!" << std::endl;
    }

    std::regex word_regex ("(\\S+)");
    auto words_begin = std::sregex_iterator(s.begin(), s.end(), word_regex);
    auto words_end = std::sregex_iterator();

    std::cout << "Found "
              << std::distance(words_begin, words_end)
              << " words\n";

    const int N = 6;
    std::cout << "Words longer than " << N << " characters:\n";
    for (std::sregex_iterator i = words_begin; i != words_end; ++i)
    {
        std::smatch match = *i;
        std::string match_str = match.str();
        if (match_str.size() > N)
        {
            std::cout << " --> " << match_str << std::endl;
        }
    }

    std::regex long_word_regex("(\\w{7,})");
    std::string new_s = std::regex_replace(s, long_word_regex, "[$&]");
    std::cout << new_s << '\n';
 }

 /*
 >regex.cpp.exe
 REGULAR EXPRESSIONS Found!
 Found 19 words
 Words longer than 6 characters:
  --> people,
  --> confronted
  --> problem,
  --> regular
  --> expressions."
  --> problems.
 Some people, when [confronted] with a [problem], think "I know, I'll use [regular] [expressions]."...
 */