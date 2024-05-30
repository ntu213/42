#include "game.hpp"

sqlite3* g_mainDB = NULL;
sqlite3* g_saveDB = NULL;

bool LoadMainDataBase()
{
	if (!g_mainDB)
	{
		std::cerr << "Database Missing" << std::endl;
		return (false);
	}
	int errorcode = sqlite3_open(DATABASE, &g_mainDB);
	if (errorcode)
	{
		std::cerr << "DataBase opening error (" << errorcode << ")" << std::endl;
		return (false);
	}
	return (true);
}

int main(int argc, char** argv)
{
	(void)argc;
	(void)argv;

	LoadMainDataBase();
	system("clear");

	// initscr();
	// for (int i = 0; i < 100; i++)
	// {
	// 	int c = getch();
	// 	// refresh();
	// 	system("clear");
	// 	std::cout << c << std::endl;
	// }
	// endwin();

	sqlite3_close(g_mainDB);

	return (0);
}
