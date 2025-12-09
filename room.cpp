class room {
public:
	int roomId;
	int price;

	room(int id, int price) : roomId(id), price(price) {}

private:

};

class singleRoom final : room {
	singleRoom(int id) : room(id, 100) {}
};

class twinRoom final : room {
	twinRoom (int id) : room(id, 150) {}
};