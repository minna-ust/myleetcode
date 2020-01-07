class Foo {
public:
    Foo() {
        count = 0;
    }

    int count;
    condition_variable cv;
    mutex mtx;

    void first(function<void()> printFirst) {
        unique_lock<mutex> lck(mtx);
        count = 2;
        cv.notify_all();
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lck(mtx);
        while (count != 2)
        {
            cv.wait(lck);
        }
        count = 3;
        cv.notify_all();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lck(mtx);
        while (count != 3)
        {
            cv.wait(lck);
        }
        count = 0;
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().foobar(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
