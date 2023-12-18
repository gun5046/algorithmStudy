#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>

using namespace std;

int t;

class Reception {
public:
	bool status = false;
	int customerId;
	int enterTime;
	int spareTime;

	void setSpareTime(int time) {
		this->spareTime = time;
	}

	void setCustomer(int enterTime, int id) {
		this->enterTime = enterTime;
		this->customerId = id;
	}

	pair<int,int> getCustomer() {
		return {this->customerId, this->enterTime};
	}
	
	int getSpareTime() {
		return this->spareTime;
	}

	bool getStatus() {
		return status;
	}
	void changeStatus() {
		this->status = !this->status;
	}
};


class Maintenance {
public:
	bool status = false;
	int customerId;
	int enterTime;
	int spareTime;
	int receptionId;
	void setSpareTime(int time) {
		this->spareTime = time;
	}

	void setCustomer(int enterTime, int id,int receptionId) {
		this->enterTime = enterTime;
		this->customerId = id;
		this->receptionId = receptionId;
	}

	pair<pair<int, int>,int> getCustomer() {
		return { { this->customerId, this->enterTime } , this->receptionId};
	}

	int getSpareTime() {
		return this->spareTime;
	}
	int getEnterTime() {
		return this->enterTime;
	}

	bool getStatus() {
		return status;
	}
	void changeStatus() {
		this->status = !this->status;
	}
};



int main() {

	cin >> t;

	for (int test = 0; test < t; test++) {
		int n, m, k, a, b;
		cin >> n >> m >> k >> a >> b;
		Reception *reception = new Reception[n+1];
		Maintenance* maintenance = new Maintenance[n+1];
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> customer; // 들어온 시각, 고객번호
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>waiting_recp_queue; // 고객번호, 들어온 시각
		queue<pair<pair<int, int>, int>>waiting_mnt_queue;

		for (int i = 0; i < n; i++) {
			int time;
			cin >> time;
			reception[i+1].setSpareTime(time);
		}
		for (int i = 0; i < m; i++) {
			int time;
			cin >> time;
			maintenance[i+1].setSpareTime(time);
		}
		for (int i = 0; i < k; i++) {
			int time;
			cin >> time;
			customer.push({ time ,i+1});
		}

		int totalCnt = customer.size();

		int time = 0;
		while (!customer.empty()) {
			pair<int, int> top = customer.top();
			if (time < top.first) break;
			waiting_recp_queue.push({top.second, top.first});
			customer.pop();
		}

		int result = 0;
		int customerCnt=0;
		while (customerCnt!=totalCnt) {
			
			for (int i = 1; i <= m; i++) {
				if (waiting_mnt_queue.empty()) break;
				if (maintenance[i].getStatus()) continue;

				pair<pair<int, int>, int> waiting_customer = waiting_mnt_queue.front();
				waiting_mnt_queue.pop();

				maintenance[i].changeStatus();
				maintenance[i].setCustomer(time, waiting_customer.first.first, waiting_customer.second);
			}
			
			for (int i = 1; i <= n; i++) {
				if (waiting_recp_queue.empty()) break;
				if (reception[i].getStatus()) continue;

				pair<int, int> waiting_customer = waiting_recp_queue.top();
				waiting_recp_queue.pop();

				reception[i].changeStatus();
				reception[i].setCustomer(time, waiting_customer.first);
			}
			time++;
			for (int i = 1; i <= m; i++) {
				if (!maintenance[i].status) continue;
				pair<pair<int, int>,int> entered_customer = maintenance[i].getCustomer();
				int spareTime = maintenance[i].getSpareTime();
				if (time - entered_customer.first.second < spareTime) continue;

				maintenance[i].changeStatus();
				if (entered_customer.second == a && i == b) result += entered_customer.first.first;
				customerCnt++;
			}			

			for (int i = 1; i <= n; i++) {
				if (!reception[i].status) continue;
				pair<int, int> entered_customer = reception[i].getCustomer();
				int spareTime = reception[i].getSpareTime();
				if (time - entered_customer.second < spareTime) continue;

				reception[i].changeStatus();
				entered_customer.second = time;
				waiting_mnt_queue.push({entered_customer,i});
			}

			

			while (!customer.empty()) {
				pair<int,int> top = customer.top();
				if (time < top.first) break;
				waiting_recp_queue.push({top.second, top.first});
				customer.pop();
			}

			
		}
		cout << "#" << test + 1 << " ";
		if (result == 0) {
			cout << -1 << "\n";
		}
		else {
			cout << result << "\n";
		}
		
		delete[] reception;
		delete[] maintenance;
	}
}