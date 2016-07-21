using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using UsedGadgetsSale.Models;
using System.Web.ModelBinding;

namespace UsedGadgetsSale
{
    public partial class GadgetList : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        public IQueryable<Gadget> GetGadgets([QueryString("id")] int? categoryId)
        {
            var _db = new UsedGadgetsSale.Models.GadgetContext();
            IQueryable<Gadget> query = _db.Gadgets;
            if (categoryId.HasValue && categoryId > 0)
            {
                query = query.Where(p => p.CategoryID == categoryId);
            }
            return query;
        }
    }
}