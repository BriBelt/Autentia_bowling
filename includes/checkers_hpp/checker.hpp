#ifndef CHECKER_HPP
# define CHECKER_HPP

# include <ctype.h>
# include <iostream>
# include <string>

class ParseInput
{
  public:
	bool check_num_players(std::string num_players_str);
	bool check_name_players(std::string &name);
	bool check_correct_round(std::string a_str, std::string b_str);
	bool check_correct_shoot(std::string a_str);

  private:
	/* data */
};

#endif