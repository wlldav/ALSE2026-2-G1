#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <mutex>

namespace Bankaccount {

class Bankaccount {
public:
    Bankaccount();
    
    void open();
    void close();
    void deposit(int amount);
    void withdraw(int amount);
    int balance();
    
private:
    bool is_open_;
    int balance_;
    std::mutex mtx_;
};

}  // namespace Bankaccount

#endif
