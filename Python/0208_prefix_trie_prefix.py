import time


class Trie:

    def __init__(self):
        self.data = dict()
        self.match = False

    def insert(self, word: str) -> None:
        self.fast_insert(word, 0)

    def fast_insert(self, word: str, index: int) -> None:
        if word[index] not in self.data:
            self.data[word[index]] = Trie()

        if index == len(word) - 1:
            self.data[word[index]].match = True
        else:
            self.data[word[index]].fast_insert(word, index + 1)

    def search(self, word: str) -> bool:
        return self.fast_search(word, 0)

    def fast_search(self, word: str, index: int):
        if word[index] not in self.data:
            return False

        if index == len(word) - 1:
            return self.data[word[index]].match

        return self.data[word[index]].fast_search(word, index + 1)

    def startsWith(self, prefix: str) -> bool:
        return self.fast_prefix(prefix, 0)

    def fast_prefix(self, prefix: str, index: int):
        if len(prefix) == index:
            return self.match or len(self.data) > 0

        if prefix[index] not in self.data:
            return False

        return self.data[prefix[index]].fast_prefix(prefix, index + 1)


# Your Trie object will be instantiated and called as such:
obj = Trie()
obj.insert("word")
param_2 = obj.search("word")
param_3 = obj.startsWith("wor")
param_4 = obj.startsWith("word")
param_5 = obj.startsWith("work")
param_6 = obj.search("words")
param_7 = obj.search("wor")
x = 1
