import java.util.List;
import java.lang.Integer;
import java.lang.Math;

class Tree{
    private List<Tree> children;
    private int data;

    boolean isLeaf(){
        return children.isEmpty();
    }

    Pair getMinMaxHeight(){
        Pair p = new Pair();
        Pair res;

        if(this.isLeaf()){
            p.min = 0;
            p.max = 0;
        }else{
            for(Tree ch : children){
                res = ch.getMinMaxHeight();
                p.max = Math.max(res.max+1,p.max);
                p.min = Math.min(res.min+1,p.min);
            }
        }

        return p;
    }

    boolean isBalanced(){
        Pair p = this.getMinMaxHeight();
        return (p.max - p.min) <= 1;
    }

    class Pair{
        public int max;
        public int min;

        public Pair(){
            min = Integer.MAX_VALUE;
            max = -1;
        }
    }
}