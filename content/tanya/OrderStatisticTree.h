/**
 * Author: Suthana Kwaonueng
 * Description: find nth largest element, count elements strictly less than x 
 * Time: O(\log N)
 */
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

ordered_set st;
//st.order_of_key(x) - find # of elements in st strictly less than x
//st.size() - size of st
//st.find_by_order(x) - return iterator to the x-th largest element
//st.clear() - clear container
