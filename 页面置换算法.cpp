
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/*
 * 说明：
 * 数据由文件读入，需要自己创建文件，然后将数据放入其中
 * 第一个数据代表内存中的页数
 * 接下来为访问次序，数据已回车分隔
*/

public class OPTTest {
	public static void main(String[] args) {
		OPT opt = new OPT("E:\\java\\io_copy\\opt.txt");
		opt.algorithm();
		system.out.println(“运行成功！”);
	}
}

class OPT {
	public OPT(String filePath) {
		memoryList = new ArrayList<Integer>();
		rd = new ReadData(filePath);
		memoryMaxSize = rd.readNext();
		processList = rd.read();
	}

	ReadData rd;
	List<Integer> processList;
	List<Integer> memoryList;
	int memoryMaxSize;

	public void algorithm() {//opt算法
		int missPage = 0;
		for (int i = 0; i < processList.size(); i++) {
			int nowProcess = processList.get(i);
			if (memoryList.contains(nowProcess)) {
				;
			} else if (memoryList.size() < memoryMaxSize) {
				missPage++;
				memoryList.add(nowProcess);
			} else {
				int val = 0, index = 0;
				for (int j = 0; j < memoryList.size(); j++) {
					int now = processList.lastIndexOf(memoryList.get(j));
					if (now > index || now < i) {
						index = now < i ? Integer.MAX_VALUE : now;
						val = memoryList.get(j);
					}
				}
				memoryList.remove(memoryList.indexOf(val));
				memoryList.add(nowProcess);
				missPage++;
			}
			for (int k = 0; k < memoryList.size(); k++) {
				System.out.println(memoryList.get(k));
			}
			System.out.println("-------------");

		}

		System.out.println(missPage);
	}
}

class ReadData {//读取数据
	public ReadData(String filePath) {
		dataList = new ArrayList<Integer>();
		try {
			bfr = new BufferedReader(new FileReader(filePath));
		} catch (FileNotFoundException e) {
			// TODO 自动生成的 catch 块
			e.printStackTrace();
		}
	}

	private BufferedReader bfr = null;
	private List<Integer> dataList;

	public List<Integer> read() {
		Integer i;
		while ((i = readNext()) != -1) {
			dataList.add(i);
		}
		return dataList;
	};

	public Integer readNext() {
		try {
			String data = bfr.readLine();
			if (data == null) {
				return -1;
			}
			return Integer.parseInt(data);
		} catch (IOException e) {
			// TODO 自动生成的 catch 块
			e.printStackTrace();
		}
		return -1;
	}
}
