
import java.util.HashMap;
import java.util.Map.Entry;
 
public class FIFOCache 
{
 
	public static int FIFO(int maxize, int[] page_req) 
  {
		int count = 0;
		HashMap<Integer, Integer> pages = new HashMap<Integer, Integer>();
		for (int j = 0; j < page_req.length; j++) 
    {
			if (pages.containsKey(Integer.valueOf(page_req[j]))) 
      {
				System.out.println(Integer.valueOf(page_req[j]) + "命中缓存!");
				// 若pages列表中有当前请求页面，就把列表时间加1；
				for (Entry<Integer, Integer> entry : pages.entrySet()) 
        {
					Integer value = entry.getValue();
					entry.setValue(Integer.valueOf(value.intValue() + 1));
					System.out.print(entry.getKey() + " 当前的保存时间：" + entry.getValue() + "\t");
				}
				System.out.println();
				continue;
			} else {
				System.out.println(Integer.valueOf(page_req[j]) + "未命中缓存!");
				// 如果缓存满了，则去除缓存中存在最久的页面
				if (pages.size() == maxize) 
        {
					int max = 0;
					int key = 0;
					for (Entry<Integer, Integer> entry1 : pages.entrySet()) 
          {
						// 求出缓存中存在最久的页面
						if (entry1.getValue().intValue() > max) {
							max = entry1.getValue().intValue();
							key = entry1.getKey().intValue();
						}
					}
					// 移除页面
					pages.remove(key);
					System.out.println(key + "被移除！");
				}
				// 就把当前缓存列表中页面的时间加1；
				for (Entry<Integer, Integer> entry : pages.entrySet()) 
        {
					Integer value = entry.getValue();
					entry.setValue(Integer.valueOf(value.intValue() + 1));
				}
				// 将新的请求页面加入缓存列表中并将其请求次数设置为0
				System.out.println(Integer.valueOf(page_req[j]) + "存入缓存!");
				pages.put(Integer.valueOf(page_req[j]), Integer.valueOf(0));
				// 统计缺页次数
				count++;
				System.out.println("当前未命中次数为：" + count);
			}
			// // 输出当前的缓存信息
			System.out.println("当前的缓存信息为：");
			for (Entry<Integer, Integer> entry : pages.entrySet()) 
      {
				Integer value =entry.getValue();
				Integer key = entry.getKey();
        
				System.out.print(key + " 在缓存中，保存时间：" + value + "\t");
			}
      
			System.out.println();
      
		}
		return count;
    
    
	}
 
	public static void main(String[] args) 
  {
		// test 1
		int maxsize = 2;
		int[] page_reg1 = { 1, 2, 1, 3, 1, 2 };
		int count = FIFO(maxsize, page_reg1);
		System.out.println("未命中总数为：" + count);
    
		System.out.println("——————————————————————————————————");
		// test 2
		maxsize = 3;
		int[] page_reg2 = { 7, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0 };
		count = FIFO(maxsize, page_reg2);
		System.out.println("未命中总数为：" + count);
		System.out.println("——————————————————————————————————");
		// test 3
    
		maxsize = 2;
    
		int[] page_reg3 = { 2, 3, 1, 3, 2, 1, 4, 3, 2 };
		count = FIFO(maxsize, page_reg3);
		System.out.println("未命中总数为：" + count);
		System.out.println("——————————————————————————————————");
    
	}
 
}
