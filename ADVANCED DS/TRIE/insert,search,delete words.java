
class TrieNode
{
	TrieNode children[] = new TrieNode[26];
	boolean isLeaf;	
}

public class Trie
{
	
	TrieNode getNode()
	{
		TrieNode temp = new TrieNode();
		for(int i=0;i<26;i++)
		{
			temp.children[i]=null;
		}
		temp.isLeaf = false;
		
		return temp;
	}
	
	boolean isFreeNode(TrieNode p)
	{
		for(int i=0;i<26;i++)
		{
			if(p.children[i]!=null)
				return false;
		}
		return true;
	}
	
	boolean deleteWordUtil(TrieNode root,String s, int depth,int len)
	{
		TrieNode p = root;
		if(p != null)
		{
			if(depth == len)
			{
				if(p.isLeaf==true)
				{
					p.isLeaf=false;
					
					if(isFreeNode(p))
						return true;
					
					return false;
				}
			}
			else
			{
				if(deleteWordUtil(p.children[s.charAt(depth)-'a'],s,depth+1,len))
				{
					p.children[s.charAt(depth)-'a'] = null;
				
					return false;
				}			
			}
		}
		return false;
	}
	void deleteWord(TrieNode root,String s)
	{
		int len = s.length();
		deleteWordUtil(root,s,0,len);
	}
	
	void insertNode(TrieNode root , String s)
	{
		TrieNode p = root;
		
		for(int i=0;i<s.length();i++)
		{
			if(p.children[s.charAt(i)-'a'] == null)
			{
				p.children[s.charAt(i)-'a'] = getNode();
			}
			p = p.children[s.charAt(i)-'a'];
		}
		p.isLeaf = true;
	}
	
	boolean searchWord(TrieNode root , String s)
	{
		TrieNode p = root;
		for(int i=0;i<s.length();i++)
		{
			if(p.children[s.charAt(i)-'a'] == null)
				return false;
			
			p = p.children[s.charAt(i)-'a'];				
		}
		
		return ( p!=null && p.isLeaf==true);
		
	}
	public static void main(String[] args)
	{
		String words[] = {"apple","mango","banana","guava","tomato"};
		
		Trie obj = new Trie();
		
		TrieNode root = obj.getNode();
		
		for(int i=0;i<words.length;i++)
		{
			obj.insertNode(root,words[i]);
		}
		
		System.out.println("tomato is present  :: "+obj.searchWord(root,"tomato")+"\n");
		
		obj.deleteWord(root, "tomato");
		System.out.println("deleting tomato from trie"+"\n");
		
		System.out.println("tomato is present  :: "+obj.searchWord(root,"tomato")+"\n");
		
	}
}