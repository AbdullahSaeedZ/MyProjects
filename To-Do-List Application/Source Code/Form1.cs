using System;
using System.Collections.Generic;
using System.Windows.Forms;
using System.IO;
using Newtonsoft.Json;


namespace ToDoList
{
    public partial class MainForm : Form
    {
        // using the Newtonsoft.Json packeges and IO Namespace classes
        // save all categories and their tasks to JSON file
        private void SaveDataToJson()
        {
            // path.combine is a method that combines and orgnize the path of more than one line.
            // the argument inside is to bring the path of the appdata folder in the user computer, then second arg is name of the folder to be created for the app.
            string folderPath = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData), "ToDoList");

            // create folder if it doesn't exist
            if (!Directory.Exists(folderPath))
                Directory.CreateDirectory(folderPath);

            string filePath = Path.Combine(folderPath, "tasks_data.json");

            // serialization is to convert the object data into a text to be used for storing or sending, the object data is automatically converted into suitable format based on object type.
            // here we Serialize TasksCategories and save the serialization text result in the json variable then save it to the JSON file on computer.
            // the formatting indented is just to format the way text is stored in the json.

            string json = JsonConvert.SerializeObject(TasksCategories, Formatting.Indented);
            File.WriteAllText(filePath, json);
        }
        private void LoadDataFromJson()
        {
            if (TasksCategories == null)
                TasksCategories = new Dictionary<string, List<TaskInfo>>();

            string folderPath = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData), "ToDoList");

            string filePath = Path.Combine(folderPath, "tasks_data.json");

            if (!File.Exists(filePath))
                return; // no saved data yet

            string json = File.ReadAllText(filePath); // take all text in the JSON file on computer

            TasksCategories = JsonConvert.DeserializeObject<Dictionary<string, List<TaskInfo>>>(json) ?? new Dictionary<string, List<TaskInfo>>();

            // the ?? means if Deserialize method fails, then return an empty dictionary instead of null if Json file was damaged or whatever.
        }
        private void RefreshCategoriesUI()
        {
            IsLoading = true;

            comboBox1.Items.Clear();

            foreach (string key in TasksCategories.Keys)
                comboBox1.Items.Add(key);

            if (comboBox1.Items.Count > 0)
            {
                comboBox1.SelectedIndex = 0;

                string categoryName = comboBox1.SelectedItem.ToString();
                UpdateChlbItems(categoryName);
                UpdateCompletedAndPendingLabels(categoryName);

                if (checkedListBox1.Items.Count > 0)
                    checkedListBox1.SelectedIndex = 0;
            }
            else
            {
                checkedListBox1.Items.Clear();
                lblPendingTasks.Text = "0";
                lblCompletedTasks.Text = "0";
            }

            IsLoading = false;
        }


        public MainForm()
        {
            InitializeComponent();
            LoadDataFromJson();
            RefreshCategoriesUI(); // after loading data to the dictionary, we show it on the app.

            btnCheckAll.Tag = true;
            btnUnCheckAll.Tag = false;
        }
        private void MainForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            SaveDataToJson();
        }


        public class TaskInfo
        {
            public string Name { set; get; }
            public bool IsCompleted { set; get; }
        }
        static public Dictionary<string, List<TaskInfo>> TasksCategories = new Dictionary<string, List<TaskInfo>>();
        short pendingCounter = 0;
        short completedCounter = 0;
        bool IsLoading;

        private void UpdateCompletedAndPendingLabels(string categoryName)
        {
            completedCounter = 0;
            pendingCounter = 0;

            foreach (TaskInfo task in TasksCategories[categoryName])
            {
                if (task.IsCompleted)
                    completedCounter++;
                else
                    pendingCounter++;
            }

            lblPendingTasks.Text = pendingCounter.ToString();
            lblCompletedTasks.Text = completedCounter.ToString();
        }
        private void UpdateChlbItems(string categoryName)
        {
            checkedListBox1.Items.Clear();

            foreach (TaskInfo oneItem in TasksCategories[categoryName])
            {
                checkedListBox1.Items.Add(oneItem.Name.ToString(), oneItem.IsCompleted); // this is an overloaded add method.
            }
        }

        private void tbTaskTyping_Enter(object sender, EventArgs e)
        {
            if (tbTaskTyping.Text == "Type Your Task Here")
                tbTaskTyping.Text = "";
        }
        private void tbTaskTyping_Leave(object sender, EventArgs e)
        {
            if (string.IsNullOrEmpty(tbTaskTyping.Text))
                tbTaskTyping.Text = "Type Your Task Here";
        }


        // once item is checked or unchecked, we have to save the change to the dictionary
        private void checkedListBox1_ItemCheck(object sender, ItemCheckEventArgs e)
        {
            if (IsLoading)
                return;

            string categoryName = comboBox1.SelectedItem.ToString();
            string TaskName = checkedListBox1.Items[e.Index].ToString(); // we take index of the checked item from e argument

            TaskInfo Task = null; // in c# all objects are by-ref, so we prepare a reference variable to connect it to the task object once found
            foreach (TaskInfo oneTask in TasksCategories[categoryName])
            {
                if (oneTask.Name == TaskName)
                {
                    Task = oneTask;
                    break;
                }
            }

            if (Task == null)
                return;

            Task.IsCompleted = (e.NewValue == CheckState.Checked);
            UpdateCompletedAndPendingLabels(categoryName);
            SaveDataToJson();
        }

        // loads values of selected key in the checked list
        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            string categoryName = comboBox1.SelectedItem.ToString();
            UpdateChlbItems(categoryName);
            UpdateCompletedAndPendingLabels(categoryName);

            if (checkedListBox1.Items.Count > 0)
                checkedListBox1.SelectedIndex = 0;
        }

        private void btnAddTask_Click(object sender, EventArgs e)
        {
            // once adding a task, the adding will trigger the ItemChecked event which will affect the labeles Counters, so i used this flag
            IsLoading = true;

            if (TasksCategories.Count == 0)
            {
                MessageBox.Show("Add Category First!", "No Categories", MessageBoxButtons.OK, MessageBoxIcon.Error);
                IsLoading = false;
                return;
            }

            if (string.IsNullOrWhiteSpace(tbTaskTyping.Text) || tbTaskTyping.Text == "Type Your Task Here")
            {
                MessageBox.Show("Enter Task Name First!", "Name Missing", MessageBoxButtons.OK, MessageBoxIcon.Error);
                IsLoading = false;
                return;
            }

            if (comboBox1.SelectedItem == null)
            {
                MessageBox.Show("Select a valid category!", "No Valid Category", MessageBoxButtons.OK, MessageBoxIcon.Error);
                IsLoading = false;
                return;
            }

            string categoryName = comboBox1.SelectedItem.ToString();
            TaskInfo Task = new TaskInfo { Name = tbTaskTyping.Text, IsCompleted = false };

            foreach (TaskInfo existing in TasksCategories[categoryName]) // if two tasks have same name, then ItemChecked event will mess up the counters
            {
                if (existing.Name == tbTaskTyping.Text)
                {
                    MessageBox.Show("Task already exists!", "Duplicate Task", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    IsLoading = false;
                    return;
                }
            }

            TasksCategories[categoryName].Add(Task);

            // ItemChecked event wont trigger here cuz of the flag
            UpdateChlbItems(categoryName);
            UpdateCompletedAndPendingLabels(categoryName);
            tbTaskTyping.Text = "Type Your Task Here";
            IsLoading = false;

            if (checkedListBox1.Items.Count > 0)
                checkedListBox1.SelectedIndex = 0;

            SaveDataToJson();
        }
        private void btnAddCategory_Click(object sender, EventArgs e)
        {
            AddCategoryForm temp = new AddCategoryForm();
            temp.ShowDialog();

            // update the combo box items after adding
            SaveDataToJson();
            RefreshCategoriesUI();

        }
        private void btnRemoveOneTask_Click(object sender, EventArgs e)
        {
            if (checkedListBox1.SelectedItem == null)
            {
                MessageBox.Show("Select a task to be deleted first!", "No Selected Task", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            string categoryName = comboBox1.SelectedItem.ToString();
            string TaskName = checkedListBox1.SelectedItem.ToString();

            TaskInfo TaskToRemove = null;
            foreach (TaskInfo oneTask in TasksCategories[categoryName])
            {
                if (oneTask.Name == TaskName)  // if i delete the item here, the foreach might give error, cuz the items where the looping is happening got disturbed by deleting
                {
                    TaskToRemove = oneTask;
                    break;
                }
            }

            if (TaskToRemove != null)
            {
                TasksCategories[categoryName].Remove(TaskToRemove);
                checkedListBox1.Items.Remove(checkedListBox1.SelectedItem);
                UpdateCompletedAndPendingLabels(categoryName);
            }

            if (checkedListBox1.Items.Count > 0)
                checkedListBox1.SelectedIndex = 0;

            SaveDataToJson();
        }
        private void btnRemoveAllTasks_Click(object sender, EventArgs e)
        {
            if (checkedListBox1.Items.Count == 0)
            {
                MessageBox.Show("No Tasks To Clear", "No Tasks", MessageBoxButtons.OK, MessageBoxIcon.Information);
                return;
            }

            if (MessageBox.Show("Confirm Clearing All Tasks", "Confirm", MessageBoxButtons.OKCancel, MessageBoxIcon.Warning) == DialogResult.OK)
            {
                string categoryName = comboBox1.SelectedItem.ToString();
                TasksCategories[categoryName].Clear();
                UpdateChlbItems(categoryName);
                UpdateCompletedAndPendingLabels(categoryName);

                SaveDataToJson();

            }
            else
                return;
            
        }

        // one click handler for check and un check all items
        private void btnCheckOruncheckAll_Click(object sender, EventArgs e)
        {
            if (comboBox1.SelectedItem == null)
            {
                MessageBox.Show("Select a valid category!", "No Valid Category", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            Button btn = ((Button)sender);
            bool IsCheckAllBtn = (bool)btn.Tag;
            string categoryName = comboBox1.SelectedItem.ToString();

            foreach (TaskInfo item in TasksCategories[categoryName])
            {
                item.IsCompleted = IsCheckAllBtn;
            }

            for (int i = 0; i < checkedListBox1.Items.Count; i++)
            {
                checkedListBox1.SetItemChecked(i, IsCheckAllBtn);
            }

            UpdateChlbItems(categoryName);
            UpdateCompletedAndPendingLabels(categoryName);

            if (checkedListBox1.Items.Count > 0)
                checkedListBox1.SelectedIndex = 0;

            SaveDataToJson();
        }

        private void btnDeleteCategory_Click(object sender, EventArgs e)
        {
            DeleteCategoryForm temp = new DeleteCategoryForm();
            temp.ShowDialog();

            SaveDataToJson();
            RefreshCategoriesUI();
        }
    }
}