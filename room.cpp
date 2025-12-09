class room {
public:
	int type=0;
	int price;
	bool reserved = false;

	room(int price, int t) : price(price), type(t) {}
};

class singleRoom final : public room {
public:
	singleRoom() : room(100, 1) {}
};

class twinRoom final : public room {
public:
	twinRoom () : room(150, 2) {}
};