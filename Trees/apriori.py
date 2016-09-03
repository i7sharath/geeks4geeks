from collections import Counter
from itertools import chain, combinations, tee


def subsets(arr):
    """ Returns non empty subsets of arr"""
    return chain(*(combinations(arr, i) for i in range(1, len(arr))))


def get_support(candidate, baskets, min_support):
    num_baskets = len(baskets)
    support = sum((candidate.issubset(basket) for basket in baskets)) / num_baskets
    if support > min_support:
        return support


def get_item_support(candidates, baskets, min_support):
    "Returns all candidates that meets a minimum support level"
    sscnt = {candidates: support for candidate, support in 
             ((candidate, get_support(candidate, baskets, min_support)) 
              for candidate in candidates)
             if support}
    
    return sscnt


def join_set(item_set, length):
    return set((i.union(j) for i in item_set for j in item_set if len(i.union(j)) == length))


def get_item_set_transaction_list(baskets):
    """Generate a list where each element is a set of the transactions
    and a set with all the unique items"""
    transactions_a, transactions_b = tee(map(frozenset, baskets), 2)
    item_set = (frozenset({i}) for i in set(chain(*transactions_a)))
    return item_set, transactions_b


def process(item, support, confidence_threshold, item_set):
    _subsets = (frozenset(x) for x in subsets(item))  # empty for 1 element items
    for element in _subsets:
        remain = item.difference(element)
        confidence = support / item_set.get(element, 0)
        if confidence >= confidence_threshold:
            yield ((tuple(element), tuple(remain)), confidence)


def generate_item_support(baskets, min_support):
    """
    run the apriori algorithm. baskets is a record iterator
    Return both:
     - items (tuple, support)
     - rules ((pretuple, posttuple), confidence)
    """
    item_set, transaction_list = get_item_set_transaction_list(baskets)

    item_support = Counter()

    current_item_support = get_item_support(item_set,
                                            transaction_list,
                                            min_support)
    k = 2
    while(current_item_support):
        item_support.update(current_item_support)
        keys_current_item_support = join_set(current_item_support.keys(), k)
        current_item_support = get_item_support(keys_current_item_support,
                                                transaction_list,
                                                min_support)
        k += 1

    return item_support


def get_rules(item_support, min_confidence):
    rules = chain(*
                  filter(None, (process(item, support, min_confidence, item_support)
                                for item, support in item_support.items())
                        )
                 )

    return rules
