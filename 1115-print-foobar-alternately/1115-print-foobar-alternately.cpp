class FooBar {
private:
    int n;
    int turn=0;
    mutex mtx;
    condition_variable cv;
public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
        	// printFoo() outputs "foo". Do not change or remove this line.
            while(turn!=0){
                cv.wait(lock);
            }
        	printFoo();
            turn=1;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
        	// printBar() outputs "bar". Do not change or remove this line.
            while(turn!=1){
                cv.wait(lock);
            }
        	printBar();
            turn=0;
            cv.notify_all();
        }
    }
};