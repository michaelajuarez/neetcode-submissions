class TrieNode:
    def __init__(self):
        self.children = [None] * 26
        self.end = False

class PrefixTree:

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        current = self.root
        for x in word:
            i = ord(x) - ord('a')
            if not current.children[i]:
                current.children[i] = TrieNode()
            current = current.children[i]
        current.end = True

    def search(self, word: str) -> bool:
        current = self.root
        for x in word:
            i = ord(x) - ord('a')
            if not current.children[i]:
                return False
            current = current.children[i]
        if current.end:
            return True
        return False

    def startsWith(self, prefix: str) -> bool:
        current = self.root
        for x in prefix:
            i = ord(x) - ord('a')
            if not current.children[i]:
                return False
            current = current.children[i]
        return True
        