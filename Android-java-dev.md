# YFL-Lab-Android

> by 王一凡 powered by Typora

# JAVA基础

```java
// 可变长数组，ArrayList继承自List
ArrayList<myClass> list = new ArrayList<myClass>();

list.add(item);

val_item = list.get(position); // position 即下标

// 数字转字符串
int number = 17;
String string = String.valueOf(number);
```



# 基础

安卓应用主要由Activity构成，每个Activity可以理解成一个页面。

所有的Acvtivity都需要在 app/src/main/ 的 AndroidManifest.xml 文件中声明，否则在打开一个未注册的Activity时会闪退：

```xml
		<activity android:name=".MainActivity">
            <intent-filter> <!-- 这个标签里面的内容只需要在主Activity中声明，一般的不需要 -->
                <action android:name="android.intent.action.MAIN" />

                <category android:name="android.intent.category.LAUNCHER" />
            </intent-filter>
        </activity>
        <activity android:name=".ObjDetailActivity"></activity>
```



Android项目结构：

核心部分：

Java代码目录：

<ProjectName> app/src/main/java/com.example.<project_name>/

素材目录（layout布局文件、各种素材等）:

<ProjectName> app/src/main/res	布局文件（.xml）在该目录layout文件夹下。

**在应用上显示浮动信息：**

Toast.makeText (Mainactivity.this, "hello", Toast.LENGTH_SHORT).show();

**注意**：在Fragment类中应该用**getActivity()**方法取代**Mainactivity.this**

**在代码中通过 id 返回 view 对象：**

findViewById(R.id.<viewId>);

**注意**：在Fragment中使用 **getView().findViewById(R.id.<viewId>);** 方法来实现view对象获取。

# 基本布局

常用标签：

LinearLayout

线性布局；主要属性orientation（vertical、horizontal）；该布局中的所有元素获得专有属性：android:layout_weight = "1" 代表该元素在一个线性布局中占整体位置的权重。

**通用属性：**

android:layout_gravity 指该元素在父元素中的停靠位置。

android:gravity 该元素中的内容停靠方向，需要多个方向时用 '|' 隔开。

# ListView & Adapter

```java
private void setListView(){
        ObjectiveListAdapter ola = new ObjectiveListAdapter(getActivity(), R.layout.obj_list_item_layout, objList);
        ListView lv = getView().findViewById(R.id.obj_list_view);
        // Toast.makeText(getActivity(), objList.get(1).name, Toast.LENGTH_SHORT).show();
        lv.setAdapter(ola);
    }

    class ObjectiveListAdapter extends ArrayAdapter{

        private int resourceId;

        public ObjectiveListAdapter(@NonNull Context context, int resource, List<WaterObjective> objLs) {
            super(context, resource, objLs);
            resourceId = resource;
        }
        @Override
        public View getView(int position, View convertView, ViewGroup parent){
            WaterObjective obj = (WaterObjective) getItem(position);

            View view = LayoutInflater.from(getContext()).inflate(resourceId, parent, false);

            TextView nameView = (TextView) view.findViewById(R.id.obj_name);
            TextView idView = (TextView) view.findViewById(R.id.obj_id);
            nameView.setText(obj.name);
            idView.setText(String.valueOf(obj.id));
            Button but = (Button) view.findViewById(R.id.obj_but);
            but.setTag(obj);
            but.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    clickedObj = (WaterObjective) v.getTag();
                    Intent i = new Intent(getActivity(), ObjDetailActivity.class);
                    startActivity(i);
                }
            });
            return view;
        }
    }
```

# Fragment & Fragments 切换

```java
// Fragment class 定义
public class MainBottomFragment extends Fragment {
    @Override
    public void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);
    }
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState){
        View view =inflater.inflate(R.layout.main_bottom_layout,container,false);
        return view;
    }
    @Override
    public void onPause(){
        super.onPause();
    }
    @Override
    public void onActivityCreated(@Nullable Bundle savedInstanceState){
        super.onActivityCreated(savedInstanceState);
        // init...

    }
}
```

```xml
<!-- 定义了一个容纳fragments的容器，可以实现多fragment的切换 -->	
	<FrameLayout
        android:id="@+id/main_top_fragment_group"
        android:layout_width="match_parent"
        android:layout_height="0dp"
        android:layout_weight="12"></FrameLayout>

<!-- 定义了一个fragment，需要在name中声明处理该fragment的class -->
    <fragment
        android:id="@+id/main_bottom_fragment"
        android:layout_width="match_parent"
        android:layout_height="0dp"
        android:layout_weight="1"
        android:name="com.example.e_water.MainBottomFragment"></fragment>

```

```java
// 定义必要的fragmentManager和对应的Trancation
    private FragmentManager manager;
    private FragmentTransaction transaction;

// 声明并实例化需要来回切换的fragment类
    private ObjListFragment frag_objList = new ObjListFragment();
    private MapFragment frag_map = new MapFragment();
    private ReportFragment frag_report = new ReportFragment();
    private UserPageFragment frag_userPage = new UserPageFragment();
	private ActiveObjectiveFragment frag_activeObj = new ActiveObjectiveFragment();

	private Fragment activeFrag = null;
	
// 先调用初始化函数
private void initFragments(){
        manager = getFragmentManager();
        switchFragment(frag_map);
    }
// 然后调用切换函数就可以实现fragment在同一FrameLayout上的切换
private void switchFragment(Fragment fragment){
        transaction = manager.beginTransaction();
        transaction.setTransition(FragmentTransaction.TRANSIT_FRAGMENT_OPEN);
        /*if(activeFrag == fragment){
            return;
        }*/
        //else{
            if(activeFrag != null){
                transaction.hide(activeFrag);
            }
            if(fragment.isAdded()){
                transaction.show(fragment);
            }
            else{
                // 这里定义了如果一个fragment没有加载到过页面中，那么就告知把这个fragment加载到对应的FrameLayout中去
                transaction.add(R.id.main_top_fragment_group, fragment);
            }
            activeFrag = fragment;
            transaction.commit();
        //}
    }
```

