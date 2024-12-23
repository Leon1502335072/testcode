#pragma once

class MaleMember;
class FemaleMember;
// 行为对应的基类
class AbstractAction
{
public:
    // 被男人访问
    virtual void maleDoing(MaleMember* male) = 0;
    // 被女人访问
    virtual void femaleDoing(FemaleMember* female) = 0;
    virtual ~AbstractAction() {}
};

class Anger : public AbstractAction
{
public:
    // 被男人访问
    void maleDoing(MaleMember* male) override;
    // 被女人访问
    void femaleDoing(FemaleMember* female) override;
    void fight();
    void warning();
};

class Horror : public AbstractAction
{
public:
    // 被男人访问
    void maleDoing(MaleMember* male) override;
    // 被女人访问
    void femaleDoing(FemaleMember* female) override;
    void help();
    void thinking();
};