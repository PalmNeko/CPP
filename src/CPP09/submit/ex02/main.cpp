#include <vector>
#include <list>

template <typename T, typename Container, typename InputIterator>
Container pmergeme(InputIterator first, InputIterator last)
{
    // pairを格納したコンテナを作る。
        // pairを作る
        // 追加する
    // イテレータをpmergemeに渡してソートしたものを受け取る。
    // main chainを作る。
        // 最初の要素のfirstを追加。
        // 残りの要素のsecondを追加。
    // sub chain ?を作る。
        // 全てのfirstを追加。(最初の要素は結局使わない)
    // main chainにsub-chainを2分挿入する。（この際何番目の要素を入れるかはあの数列を使う。）
    // pairになり切らなかった要素をmainchainに追加。
    // 結果を返す。
}

template <typename T>
std::pair<T, T> make_pmerge_pair(T val1, T val2)
{
    T first;
    T second;

    first = lessthan(val1, val2);
    second = grater_than(val1, val2);
    return std::make_pair(first, second);
}

template <typename T>
int getValue(T value)
{

}

int main(void)
{

}
