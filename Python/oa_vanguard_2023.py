from collections import deque


def getSpamEmails(subjects, spam_words):
    spam_set = set(word.lower() for word in spam_words)
    return ["spam" if sum(w.lower() in spam_set for w in subject.split()) >= 2 else "not_spam" for subject in subjects]


def isPangram(pangram):
    return "".join(str(int(len(set([ch for ch in sent]).difference(" ")) == 26)) for sent in pangram)


def missingWords(s: str, t):
    t_ls = deque(t.split())
    s_ls = deque(s.split())
    ret = []
    while len(s_ls) > 0:
        word = s_ls.popleft()
        if len(t_ls) > 0 and word == t_ls[0]:
            t_ls.popleft()
        else:
            ret.append(word)
    return ret


print(missingWords("I am using hackerrank to improve programming", "am hackerrank to improve"))
