#include <iostream>

// 8 vida, 8 balas, 4 compañeros, 8 empty, 1 berk, 1 shield, 1 infBullets, 1 god
class data
{
	int dataInt = 0;

public:
	const int shift_bullets = 16;
	const int shift_infBullets = 1;

	const int sel_bullets = 0b11111111 << shift_bullets;
	const int sel_infBullets = 0b1 << shift_infBullets;

	int get_bullets() const { return (dataInt & sel_bullets) >> shift_bullets; }

	void add_bullets(const int& value)
	{
		int bullets = get_bullets();
		int total = value + bullets;
		int result = (total << shift_bullets) & sel_bullets;
		dataInt &= ~(bullets << shift_bullets);
		dataInt |= result;
	}

	bool is_infBullets() const { return dataInt & sel_infBullets; }

	void activate_infBullets() { dataInt |= sel_infBullets; }
};

int main()
{
	data player;

	std::cout << "is_infBullets: " << player.is_infBullets() << std::endl;
	player.activate_infBullets();
	std::cout << "is_infBullets: " << player.is_infBullets() << std::endl;

	std::cout << std::endl;

	std::cout << "add_bullets: 10 " << std::endl;
	player.add_bullets(10);
	std::cout << "add_bullets: 20 " << std::endl;
	player.add_bullets(20);
	std::cout << "    get_bullets: " << player.get_bullets() << std::endl;
	std::cout << "add_bullets: -25 " << std::endl;
	player.add_bullets(-25);
	std::cout << "    get_bullets: " << player.get_bullets() << std::endl;
}

